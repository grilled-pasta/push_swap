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

int		ft_position(stack *a, int rank)
{
	int	position;

	position = 0;
	while (a)
	{
		if (a->rank == rank)
			return (position);
		a = a->next;
		position++;
	}
	return (-1);
}

void	sort_three(stack **a, stack **operations)
{
	int first;
	int	second;
	int	third;

	first = (*a)->rank;
	second = (*a)->next->rank;
	third = (*a)->next->next->rank;
	if (first == 1 && second == 2 && third == 0)
		reverse_rotate_a(a, operations);
	else if (first == 2 && second == 0 && third == 1)
		rotate_a(a, operations);
	else if (first == 2 && second == 1 && third == 0)
	{
		rotate_a(a, operations);
		swap_a(a, operations);
	}
	else if (first == 1 && second == 0 && third == 2)
		swap_a(a, operations);
	else
	{
		reverse_rotate_a(a, operations);
		swap_a(a, operations);
	}
}

void	simple(stack **a, stack **b, stack **operations)
{
	int		rank;
	int		size;
	int		position;

	if (!a || !*a || !b)
		return ;
	ft_ranking(a);
	size = ft_lstsize(*a);
	if (size == 2)
	{
		swap_a(a, operations);
		return ;
	}
	else if (size == 3)
	{
		sort_three(a, operations);
		return ;
	}
	rank = 0;
	while (*a && rank < size -1)
	{
		position = ft_position(*a, rank); // if position == -1 => error?
		while ((*a)->rank != rank)
		{
			if (position < size / 2)
				rotate_a(a, operations);
			else
				reverse_rotate_a(a, operations);
		}
		if (is_sorted(*a))
			break ;
		push_b(a, b, operations);
		rank++;
	}
	while (*b)
		push_a(a, b, operations);
}
