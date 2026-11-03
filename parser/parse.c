/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alkonsta@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 04:56:39 by alla              #+#    #+#             */
/*   Updated: 2026/11/03 17:49:25 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

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
	return (strcmp(arg, "--simple") == 0);
}

args	*parse_args(int argc, char **argv)
{
	args	*args_parsed;
	stack	*s;
	stack	*temp;
	int		i;

	i = 1;
	args_parsed = malloc(sizeof(args));
	s = malloc(sizeof(stack));
	if (!args_parsed)
		return (NULL);
	args_parsed->strategy = "adaptive";
	if (is_strategy(argv[i]))
	{
		args_parsed->strategy = argv[i] + 2;
		printf("strategy: %s\n", args_parsed->strategy);
		i++;
	}
	while (i < argc)
	{
		temp = new(atoi(argv[i]));
		if ((strcmp(argv[i], "0") != 0 && temp->number == 0) 
				|| !is_unique(s, temp->number))
			return (clear(s), free(temp), printf("Error\n"), NULL);
		add_back(&s, temp);
		i++;
	}
	args_parsed->stack = s;
	args_parsed->disorder = compute_disorder(args_parsed->stack);
	return (args_parsed);
}
