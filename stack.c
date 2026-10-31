/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:39:59 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/31 01:40:01 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*new(int number)
{
	stack	*s;

	s = (stack *) malloc(sizeof(stack));
	if (!s)
		return (NULL);
	s->number = number;
	s->next = NULL;
	return (s);
}

void	add_front(stack **s, stack *s_new)
{
	if (*s)
		s_new->next = *s;
	*s = s_new;
}

void	add_back(stack **s, stack *s_new)
{
	stack	*last_s;
	
	if (!*s)
	{
		*s = s_new;
		return ;
	}
	last_s = last(*s);
	last_s->next = s_new;
}

stack	*last(stack *s)
{
	while (s && s->next)
		s = s->next;
	return (s);
}

stack	*element(stack *s, int index)
{
	int	i;

	i = 0;
	while (s && i < index)
	{
		s = s->next;
		i++;
	}
	return (s);
}

int		size(stack *s)
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
