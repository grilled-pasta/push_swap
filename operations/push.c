/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 18:33:36 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/01 01:57:02 by alkonsta         ###   ########.fr       */
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

void	pa(stack **a, stack **b)
{
	push(a, b);
}

void	pb(stack **a, stack **b)
{
	push(b, a);
}

