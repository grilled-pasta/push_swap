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

#include "common.h"
#include "push_swap.h"

static int	ft_position(t_stack *a, int rank)
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

static void	sort(t_stack **a, t_stack **b, t_stack **operations)
{
	int		rank;
	int		size;
	int		position;

	rank = 0;
	size = ft_lstsize(*a);
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

void	simple(t_stack **a, t_stack **b, t_stack **operations)
{
	if (!a || !*a || !b)
		return ;
	if (ft_lstsize(*a) > 2)
		sort(a, b, operations);
	else
		swap_a(a, operations);
}
