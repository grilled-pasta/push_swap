/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 04:56:39 by alla              #+#    #+#             */
/*   Updated: 2026/11/07 18:42:27 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(stack *s)
{
	int		mistakes;
	int		total_pairs;
	stack	*temp;

	mistakes = 0;
	total_pairs = 0;
	while (s && s->next)
	{
		temp = s->next;
		while (temp)
		{
			total_pairs += 1;
			if (s->number > temp->number)
				mistakes += 1;
			temp = temp->next;
		}
		s = s->next;
	}
	return (mistakes / (float) total_pairs);
}

static int	is_unique(stack *s, int number)
{
	while (s)
	{
		if (s->number == number)
			return (0);
		s = s->next;
	}
	return (1);
}

static int	is_strategy(char *arg)
{
	return (ft_strcmp(arg, "--adaptive") == 0 || ft_strcmp(arg, "--simple") == 0 
			|| ft_strcmp(arg, "--medium") == 0 || ft_strcmp(arg, "--complex") == 0);
}

static int	is_number(char *s)
{
	if (!s || !*s) 
		return (0);
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!is_digit(*s))
			return (0);
		s++;
	}
	return (1);
}

static void	select_adaptive(args *args)
{
	if (args->disorder <= 0.2 || ft_lstsize(args->stack) <= 5)
		args->strategy = "simple";
	else if (args->disorder <= 0.5)
		args->strategy = "medium";
	else
		args->strategy = "complex";
}

args	*parse_args(int argc, char **argv)
{
	args	*args_parsed;
	stack	*s;
	stack	*temp_s;
	int		i;
	int		temp_i;

	i = 1;
	args_parsed = malloc(sizeof(args));
	s = NULL;
	if (!args_parsed || argc == 1)
		return (free(args_parsed), NULL);
	args_parsed->adaptive = 1;
	args_parsed->benchmark = 0;
	if (ft_strcmp(argv[i], "--bench") == 0)
	{
		args_parsed->benchmark = 1;
		i++;
	}
	if (i < argc && is_strategy(argv[i]))
	{
		args_parsed->strategy = argv[i] + 2;
		if (ft_strcmp(args_parsed->strategy, "adaptive") != 0)
			args_parsed->adaptive = 0;
		i++;
	}
	while (i < argc)
	{
		if (!is_number(argv[i])) 
			return (clear(s), free(args_parsed), NULL);
		temp_i = ft_atoi(argv[i]);
		if ((temp_i == 0 && ft_strcmp(argv[i], "0") != 0)
				|| !is_unique(s, temp_i))
			return (clear(s), free(args_parsed), NULL);
		temp_s = new(temp_i);
		if (!temp_s)
			return (clear(s), clear(temp_s), free(args_parsed), NULL);
		add_back(&s, temp_s);
		i++;
	}
	args_parsed->stack = s;
	args_parsed->disorder = compute_disorder(args_parsed->stack);
	if (args_parsed->adaptive)
		select_adaptive(args_parsed);
	return (args_parsed);
}
