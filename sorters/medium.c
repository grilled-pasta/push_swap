/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 21:25:52 by fsalinas          #+#    #+#             */
/*   Updated: 2026/11/06 21:25:31 by fsalinas         ###   ########.fr       */
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
static void	ft_push_chunk(stack **a, stack **b, stack **operations, t_chunk *chunk)
{
	while (chunk->remaining > 0)
	{
		if ((*a)->rank >= chunk->index * chunk->size
			&& (*a)->rank < (chunk->index + 1) * chunk->size)
		{
			push_b(a, b, operations);
			chunk->remaining--;
		}
		else
			rotate_a(a, operations);
	}
}

void	a_to_b(stack **a, stack **b, int chunk_size, stack **operations)
{
	t_chunk	chunk;
	int		size;
	int		chunks;

	if (!a || !*a || chunk_size <= 0)
		return ;
	size = ft_lstsize(*a);
	chunks = (size + chunk_size - 1) / chunk_size;
	chunk.size = chunk_size;
	chunk.index = 0;
	while (chunk.index < chunks)
	{
		chunk.remaining = chunk_size;
		if (chunk.index == chunks - 1)
			chunk.remaining = size - chunk_size * (chunks - 1);
		ft_push_chunk(a, b, operations, &chunk);
		chunk.index++;
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
void b_to_a(stack **a, stack **b, int chunk_size, stack **operations)
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
			rotate_b(b, operations);
			i++;
		}
		push_a(a, b, operations);
		while (i > 0)
		{
			reverse_rotate_b(b, operations);
			i--;
		}
		chunk_size--;
	}
}
//repeats b_to_a for each chunk
void ft_chunks(stack **a, stack **b, int chunks, 
		stack **operations)
{
	int size;
	int	chunk_size;
	
	size = ft_lstsize(*b);
	chunks = (size + chunk_size - 1) / chunk_size;
	b_to_a(a, b, size - (chunk_size * (chunks-1)), operations);
	chunks--;
	while (chunks > 0)
	{
		b_to_a(a, b, chunk_size, operations);
		chunks--;
	}
}
int medium(stack **a, stack **b, stack **operations)
{
	int size;
	int chunk_size;
	int chunks;

	size = ft_lstsize(*a);
	if (size == 0)
		return(1);
	chunk_size = (int) ft_sqrt(size);
	if (chunk_size * chunk_size < size)
    	chunk_size++;
	chunks = (size + chunk_size - 1) / chunk_size;
	ft_ranking(a);
	a_to_b(a, b, chunk_size, operations);
	ft_chunks(a, b, chunks, operations);
	return(1);
}
