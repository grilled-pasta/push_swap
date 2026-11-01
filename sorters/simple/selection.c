/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 00:58:51 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/01 02:29:20 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		stack_min(stack **s)
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

void	sort_simple_selection(stack **a, stack **b)
{
	int		min;

	if (!a || !*a)
		return ;
	while (*a && (*a)->next)
	{
		min = stack_min(a);
		while ((*a)->number != min)
		{
			printf("ra\n");
			ra(a);
		}
		printf("pb\n");
		pb(a, b);
	}
	while (*b)
	{
		printf("pa\n");
		pa(a, b);
	}
}
