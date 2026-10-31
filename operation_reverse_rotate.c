/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 00:23:24 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/01 00:29:30 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(stack **s)
{
	stack	*s_temp; // second to last
	stack	*s_last;

	s_temp = *s;
	while (s_temp->next->next != NULL)
		s_temp = s_temp->next;
	s_last = s_temp->next;

	s_last->next = *s;
	s_temp->next = NULL;
	*s = s_last;
}

void	rra(stack **a)
{
	reverse_rotate(a);
}

void	rrb(stack **b)
{
	reverse_rotate(b);
}

void	rrr(stack **a, stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
