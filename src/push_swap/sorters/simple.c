/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 00:58:51 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/03 17:45:56 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_position(t_stack *a, int rank)
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

void	simple(t_stack **a, t_stack **b, t_stack **operations)
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
	rank = 0;
	while (*a && rank < size -1)
	{
		position = ft_position(*a, rank);
		while ((*a)->rank != rank)
		{
			if (position < (size - 1) / 2)
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