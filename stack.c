/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:39:59 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/03 17:49:32 by alla             ###   ########.fr       */
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
	
	if (*s)
	{
		last_s = last(*s);
		last_s->next = s_new;
	}
	else
		*s = s_new;
}

int		ft_lstsize(stack *s)
{
	int	size;

	size = 0;
	while (s)
	{
		size++;
		s=s->next;
	}
	return (size);
}
