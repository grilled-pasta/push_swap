/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 04:54:06 by alla              #+#    #+#             */
/*   Updated: 2026/11/13 03:58:28 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
#include "common.h"

t_stack	*last(t_stack *s)
{
	while (s && s->next)
		s = s->next;
	return (s);
}

int	size(t_stack *s)
{
	int	size;

	size = 0;
	while (s)
	{
		s = s->next;
		size++;
	}
	return (size);
}

void	iter(t_stack *s, void (*f)(int))
{
	while (s)
	{
		f(s->number);
		s = s->next;
	}
}

void	clear(t_stack *s)
{
	t_stack	*temp;

	while (s)
	{
		temp = s;
		s = s->next;
		free(temp);
	}
	free(s);
}

int	is_sorted(t_stack *s)
{
	int	prev;

	if (!s)
		return (1);
	prev = s->number;
	s = s->next;
	while (s)
	{
		if (s->number < prev)
			return (0);
		prev = s->number;
		s = s->next;
	}
	return (1);
}
