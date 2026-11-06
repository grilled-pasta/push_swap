/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 00:58:51 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/03 17:45:56 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_min(stack **s)
{
	stack	*temp;
	int		min;

	if (!s || !*s)
		return (0);
	temp = *s;
	min = temp->number;
	while (temp)
	{
		if (temp->number < min)
			min = temp->number;
		temp = temp->next;
	}
	return (min);
}

void		simple(stack **a, stack **b, stack **operations)
{
	int		min;

	if (!a || !*a)
		return ;
	while (*a && (*a)->next)
	{
		min = stack_min(a);
		while ((*a)->number != min)
			rotate_a(a, operations);
		push_b(a, b, operations);
	}
	while (*b)
		push_a(a, b, operations);
}
