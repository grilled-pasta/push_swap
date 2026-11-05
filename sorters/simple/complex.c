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

void ft_ranking(stack **a)
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
int bin_checker(stack **a, stack **b, int size, int bit)
{
	int i;
	int to_b;

	i = 0;
	to_b = 0;
	while(i < size)
	{
		if((*a)->rank >> bit & 1)
			ra(a);
		else
		{
			pb(a, b);
			to_b++;
		}
		i++;
	}
	return(to_b);
}
void complex_b_to_a(stack **a, stack **b, int to_b)
{
	while (to_b > 0)
	{
		pa(a, b);
		to_b--;
	}
}
int complex(stack **a, stack **b)
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
		moved = bin_checker(a, b, size, bit);	
		complex_b_to_a(a, b, moved);
		bit++;
	}
	return(1);
}