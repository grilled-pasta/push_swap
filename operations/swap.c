/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:22:10 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/01 01:57:32 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(stack **s)
{
	stack	*s1;
	stack	*s2;

	if (!s || !*s || !(*s)->next)
		return ;
	s1 = *s;
	s2 = s1->next;

	s1->next = s2->next;
	s2->next = s1;
	*s = s2;
}

void	swap_a(stack **a, stack **operations)
{
	swap(a);
	add_back(operations, new(sa));
}

void	swap_b(stack **b, stack **operations)
{
	swap(b);
	add_back(operations, new(sa));
}

void	swap_ab(stack **a, stack **b, stack **operations)
{
	swap(a);
	swap(b);
	add_back(operations, new(sa));
}
