/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 23:11:26 by fsalinas          #+#    #+#             */
/*   Updated: 2026/11/05 23:45:33 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			{
				current->rank++;
			}
			temp = temp->next;
		}
		current = current->next;
		temp = *a;
	}
}
int bin_checker(stack **a, stack **b, int bit, stack **operations)
{
	int i;
	int to_b;
	int	size;

	i = 0;
	to_b = 0;
	size = ft_lstsize(*a);
	while(i < size)
	{
		if((*a)->rank >> bit & 1)
			rotate_a(a, operations);
		else
		{
			push_b(a, b, operations);
			to_b++;
		}
		i++;
	}
	return(to_b);
}
void complex_b_to_a(stack **a, stack **b, int to_b, stack **operations)
{
	while (to_b > 0)
	{
		push_a(a, b, operations);
		to_b--;
	}
}
int complex(stack **a, stack **b, stack **operations)
{
	int size;
	int bit;
	int moved;
	int max_bits;
	int max_rank;

	ft_ranking(a);
	size = ft_lstsize(*a);
	bit = 0;
	max_bits = 0;
	max_rank = size -1;
	while (max_rank > 0)
	{
		max_rank = max_rank >> 1;
		max_bits++;
	}
	while(bit < max_bits)
	{
		moved = bin_checker(a, b, bit, operations);	
		complex_b_to_a(a, b, moved, operations);
		bit++;
	}
	return(1);
}
