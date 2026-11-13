/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 04:54:06 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 03:58:28 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

t_stack	*last(t_stack *s)
{
	while (s && s->next)
		s = s->next;
	return (s);
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

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->number > a->next->number)
			return (0);
		a = a->next;
	}
	return (1);
}

int	add_operation(t_operation operation, t_stack **operations)
{
	t_stack	*temp;

	if (!operations)
		return (-1);
	temp = new(operation);
	if (!temp)
		return (-1);
	add_back(operations, temp);
	return (0);
}
