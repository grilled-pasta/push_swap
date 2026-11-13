/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:39:59 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 04:08:09 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new(int number)
{
	t_stack	*s;

	s = (t_stack *) malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->number = number;
	s->next = NULL;
	return (s);
}

void	add_front(t_stack **s, t_stack *s_new)
{
	if (*s)
		s_new->next = *s;
	*s = s_new;
}

void	add_back(t_stack **s, t_stack *s_new)
{
	t_stack	*last_s;

	if (!s)
		return ;
	if (*s)
	{
		last_s = last(*s);
		last_s->next = s_new;
	}
	else
		*s = s_new;
}

int	ft_lstsize(t_stack *s)
{
	int	size;

	size = 0;
	while (s)
	{
		size++;
		s = s->next;
	}
	return (size);
}
