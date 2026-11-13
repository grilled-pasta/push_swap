/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 04:56:39 by alla              #+#    #+#             */
/*   Updated: 2026/11/13 06:54:32 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_adaptive(t_args *args)
{
	if (args->disorder <= 0.2 || ft_lstsize(args->stack) <= 5)
		args->strategy = "simple";
	else if (args->disorder <= 0.5)
		args->strategy = "medium";
	else
		args->strategy = "complex";
}

int	parse_flags(int argc, char **argv, t_args **args)
{
	int	i;

	i = 1;
	if (ft_strcmp(argv[i], "--bench") == 0)
	{
		(*args)->benchmark = 1;
		i++;
	}
	if (i < argc && is_strategy(argv[i]))
	{
		(*args)->strategy = argv[i] + 2;
		if (ft_strcmp((*args)->strategy, "adaptive") != 0)
			(*args)->adaptive = 0;
		i++;
	}
	return (i);
}

t_stack	*parse_stack(int i, int argc, char **argv)
{
	t_stack	*s;
	t_stack	*temp_s;
	int		temp_i;

	s = NULL;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (clear(s), NULL);
		temp_i = ft_atoi(argv[i]);
		if ((temp_i == 0 && ft_strcmp(argv[i], "0") != 0)
			|| !is_unique(s, temp_i))
			return (clear(s), NULL);
		temp_s = new(temp_i);
		if (!temp_s)
			return (clear(s), clear(temp_s), NULL);
		add_back(&s, temp_s);
		i++;
	}
	return (s);
}

t_args	*parse_args(int argc, char **argv, int has_flags)
{
	t_args	*args_parsed;
	int		i;

	i = 1;
	args_parsed = malloc(sizeof(t_args));
	if (!args_parsed || argc == 1)
		return (free(args_parsed), NULL);
	args_parsed->adaptive = 1;
	args_parsed->benchmark = 0;
	if (has_flags)
		i = parse_flags(argc, argv, &args_parsed);
	args_parsed->stack = parse_stack(i, argc, argv);
	if (!args_parsed->stack)
		return (free(args_parsed), NULL);
	args_parsed->disorder = compute_disorder(args_parsed->stack);
	if (args_parsed->adaptive)
		select_adaptive(args_parsed);
	return (args_parsed);
}
