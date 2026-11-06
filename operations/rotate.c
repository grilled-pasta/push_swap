/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 00:11:39 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/01 01:58:09 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(stack **s)
{
	stack	*temp;

	if (!s || !*s || !(*s)->next)
		return ;
	temp = *s;
	last(*s)->next = *s;
	*s = temp->next;
	temp->next = NULL;
}

void	rotate_a(stack **a, stack **operations)
{
	rotate(a);
	add_back(operations, new(ra));
}

void	rotate_b(stack **b, stack **operations)
{
	rotate(b);
	add_back(operations, new(rb));
}

void	rotate_ab(stack **a, stack **b, stack **operations)
{
	rotate(a);
	rotate(b);
	add_back(operations, new(rr));
}
