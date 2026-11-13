/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:31:53 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 08:46:26 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

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

static int	is_unique(t_stack *s, int number)
{
	while (s)
	{
		if (s->number == number)
			return (0);
		s = s->next;
	}
	return (1);
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
