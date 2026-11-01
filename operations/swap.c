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

void	sa(stack **a)
{
	swap(a);
}

void	sb(stack **b)
{
	swap(b);
}

void	ss(stack **a, stack **b)
{
	swap(a);
	swap(b);
}
