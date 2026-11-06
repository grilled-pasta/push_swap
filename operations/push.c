/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 18:33:36 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/03 17:47:29 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(stack **s1, stack **s2)
{
	stack	*temp;

	if (!s2 || !*s2)
		return ;
	temp = *s2;
	*s2 = (*s2)->next;
	temp->next = NULL;
	add_front(s1, temp);
}

void	push_a(stack **a, stack **b, stack **operations)
{
	push(a, b);
	add_back(operations, new(pa));
}

void	push_b(stack **a, stack **b, stack **operations)
{
	push(b, a);
	add_back(operations, new(pb));
}

