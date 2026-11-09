/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 00:23:24 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/09 22:26:58 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(stack **s)
{
	stack	*s_temp;
	stack	*s_last;

	if (!s || !*s || !(*s)->next)
		return ;
	s_temp = *s;
	while (s_temp->next->next != NULL)
		s_temp = s_temp->next;
	s_last = s_temp->next;
	s_last->next = *s;
	s_temp->next = NULL;
	*s = s_last;
}

void	reverse_rotate_a(stack **a, stack **operations)
{
	reverse_rotate(a);
	add_back(operations, new(rra));
}

void	reverse_rotate_b(stack **b, stack **operations)
{
	reverse_rotate(b);
	add_back(operations, new(rrb));
}

void	reverse_rotate_ab(stack **a, stack **b, stack **operations)
{
	reverse_rotate(a);
	reverse_rotate(b);
	add_back(operations, new(rrr));
}
