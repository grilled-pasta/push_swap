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
#include <stdio.h>

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

void	ra(stack **a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(stack **b)
{
	rotate(b);
	printf("rb\n");
}

void	rr(stack **a, stack **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}
