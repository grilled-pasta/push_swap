/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 04:54:06 by alla              #+#    #+#             */
/*   Updated: 2026/11/09 22:30:58 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*last(stack *s)
{
	while (s && s->next)
		s = s->next;
	return (s);
}

int	size(stack *s)
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

void	iter(stack *s, void (*f)(int))
{
	while (s)
	{
		f(s->number);
		s = s->next;
	}
}

void	clear(stack *s)
{
	stack	*temp;

	while (s)
	{
		temp = s;
		s = s->next;
		free(temp);
	}
	free(s);
}
