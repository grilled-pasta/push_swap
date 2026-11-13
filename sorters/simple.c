/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 00:58:51 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/09 22:24:48 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ranksearch(stack **a, int rank)
{
	int		position;
	stack	*temp;

	position = 0;
	temp = *a;
	while (temp)
	{
		if (temp->rank == rank)
			return (position);
		position++;
		temp = temp->next;
	}
	return (-1);
}

void	ft_move(stack **a, stack **b, stack **operations, int rank)
{
	int		position;
	int		size_a;

	size_a = ft_lstsize (*a);
	position = ft_ranksearch (a, rank);
	if (position <= size_a / 2)
	{
		while (position > 0)
		{
			rotate_a (a, operations);
			position--;
		}
	}
	else
	{
		while (size_a - position > 0)
		{
			reverse_rotate_a (a, operations);
			position++;
		}
	}
	push_b (a, b, operations);
}

void	simple(stack **a, stack **b, stack **operations)
{
	int	rank;
	int	size_a;

	rank = 0;
	size_a = ft_lstsize(*a);
	ft_ranking(a);
	while (rank < size_a)
	{
		ft_move(a, b, operations, rank);
		rank++;
	}
	while (*b)
	{
		push_a(a, b, operations);
	}
}
