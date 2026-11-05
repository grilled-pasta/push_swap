/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 21:25:52 by fsalinas          #+#    #+#             */
/*   Updated: 2026/11/05 20:51:56 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// calculates the ranking of each number on A
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
// square root to calculate amount of chunks
double ft_sqrt(double n)
{
    double x;
    int i;

    if (n < 0)
        return (-1);
    if (n == 0)
        return (0);
    x = n;
    i = 0;
    while (i < 20)
    {
        x = (x + n / x) / 2;
        i++;
    }
    return (x);
}
//sends the organized chunks with unorganized values from A to B
void a_to_b(stack **a, stack **b, int chunk_size, int chunks)
{
	int temp;
	int i;
	int size;

	size = ft_lstsize(*a);
	i = 0;
	temp = chunk_size;
	while (i < chunks)
	{
		if (i+2 > chunks)
			chunk_size = size - (chunk_size * (chunks-1));
		while (chunk_size > 0)
		{
			if ((*a)->rank >= temp*i && (*a)->rank < (i+1)*temp)
			{
				pb(a, b);
				chunk_size--;
			}
			else
				ra(a);
		}
		chunk_size = temp;
		i++;
	}
}

//checks each chunk and looks where is the max value located.
int ft_find_max(stack *b, int chunk_size)
{
	int max;
	int i;
	int maxpos;
	stack *temp;

	if (!b || chunk_size <= 0)
		return(-1);
	i = 1;
	maxpos = 0;
	temp = b->next;
	max = b->number;
	while (i < chunk_size)
	{
		if (!temp)
			return(-1);
		if (max < temp->number)
		{
			maxpos = i;
			max = temp->number;
		}
		temp = temp->next;
		i++;
		
	}
	return (maxpos);
}

//checks the top chunk on stack B and sends it back to stack A in order
void b_to_a(stack **a, stack **b, int chunk_size)
{
	int maxpos;
	int i;

	while (chunk_size > 0)
	{
		i = 0;
		maxpos = ft_find_max(*b, chunk_size);
		if (maxpos == -1)
			return;
		while (maxpos > i)
		{
			rb(b);
			i++;
		}
		pa(a, b);
		while (i > 0)
		{
			rrb(b);
			i--;
		}
		chunk_size--;
	}
}
//repeats b_to_a for each chunk
void ft_chunks(stack **a, stack **b, int chunk_size, int chunks)
{
	int size;

	size = ft_lstsize(*b);
	b_to_a(a, b, size - (chunk_size * (chunks-1)));
	chunks--;
	while (chunks > 0)
	{
		b_to_a(a, b, chunk_size);
		chunks--;
	}
}
int medium(stack **a, stack **b)
{
	int size;
	int chunk_size;
	int chunks;

	size = ft_lstsize(*a);
	if (size == 0)
		return(1);
	chunk_size = (int)ft_sqrt(size);
	if (chunk_size * chunk_size < size)
    	chunk_size++;
	chunks = (size + chunk_size - 1) / chunk_size;
	ft_ranking(a);
	a_to_b(a, b, chunk_size, chunks);
	ft_chunks(a, b, chunk_size, chunks);
	return(1);
}
