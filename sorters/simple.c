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

// calculates the ranking of each number on A
static void ft_ranking(stack **a)
{
	stack *current;
	stack *temp;
	
	current = *a;
	temp = *a;
	while (current)
	{
		current->rank = 0;
		while (temp)
		{
			if (current->number > temp->number)
				current->rank++;
			temp = temp->next;
		}
		current = current->next;
		temp = *a;
	}
}

void		simple(stack **a, stack **b, stack **operations)
{
	int		min;
	int		size;

	if (!a || !*a || !b)
		return ;
	size = ft_lstsize(*a);
	ft_ranking(a);
	min = 0;
	while (*a && (*a)->next && min < size)
	{
		while ((*a)->rank != min)
		{
			if ((*a)->rank > size / 2)
				reverse_rotate_a(a, operations);
			else
				rotate_a(a, operations);
		}
		push_b(a, b, operations);
		min++;
	}
	while (*b)
		push_a(a, b, operations);
}
