/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 04:56:39 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 09:49:03 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static float	compute_disorder(t_stack *s)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*temp;

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

static int	is_strategy(char *arg)
{
	return (ft_strcmp(arg, "--adaptive") == 0
		|| ft_strcmp(arg, "--simple") == 0
		|| ft_strcmp(arg, "--medium") == 0
		|| ft_strcmp(arg, "--complex") == 0);
}

static void	select_adaptive(t_args *args)
{
	if (args->disorder <= 0.2 || ft_lstsize(args->stack) <= 5)
		args->strategy = "simple";
	else if (args->disorder <= 0.5)
		args->strategy = "medium";
	else
		args->strategy = "complex";
}

static int	parse_flags(int argc, char **argv, t_args **args)
{
	int	i;

	i = 1;
	while (i < argc && ft_strncmp(argv[i], "--", 2) == 0)
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
		{
			if ((*args)->benchmark)
				return (-1);
			(*args)->benchmark = 1;
		}
		else if (is_strategy(argv[i]))
		{
			if ((*args)->strategy)
				return (-1);
			(*args)->strategy = argv[i] + 2;
			if (ft_strcmp((*args)->strategy, "adaptive") != 0)
				(*args)->adaptive = 0;
		}
		else
			return (-1);
		i++;
	}
	return (i);
}

t_args	*parse_args(int argc, char **argv)
{
	t_args	*args;
	int		i;

	i = 1;
	args = malloc(sizeof(t_args));
	if (!args || argc == 1)
		return (free(args), NULL);
	args->adaptive = 1;
	args->benchmark = 0;
	i = parse_flags(argc, argv, &args);
	if (i == -1)
		return (free(args), NULL);
	args->stack = parse_stack(i, argc, argv);
	if (!args->stack)
		return (free(args), NULL);
	ft_ranking(&args->stack);
	args->disorder = compute_disorder(args->stack);
	if (args->adaptive)
		select_adaptive(args);
	return (args);
}
