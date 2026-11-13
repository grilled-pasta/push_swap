/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 21:25:52 by fsalinas          #+#    #+#             */
/*   Updated: 2026/11/09 22:41:15 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

//sends the organized chunks with unorganized values from A to B
void	a_to_b(t_stack **a, t_stack **b, t_stack **operations, t_chunk *chunk)
{
	int	temp;
	int	i;
	int	size;

	size = ft_lstsize(*a);
	i = 0;
	temp = chunk->size;
	while (i < chunk->count)
	{
		if (i + 2 > chunk->count)
			chunk->size = size - (chunk->size * (chunk->count - 1));
		while (chunk->size > 0)
		{
			if ((*a)->rank >= temp * i && (*a)->rank < (i + 1) * temp)
			{
				push_b(a, b, operations);
				chunk->size--;
			}
			else
				rotate_a(a, operations);
		}
		chunk->size = temp;
		i++;
	}
}

//checks the top chunk on t_stack B and sends it back to t_stack A in order
void	b_to_a(t_stack **a, t_stack **b, t_stack **operations, int chunk_size)
{
	int	maxpos;
	int	i;

	while (chunk_size > 0)
	{
		i = 0;
		maxpos = ft_find_max(*b, chunk_size);
		if (maxpos == -1)
			return ;
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
void	ft_chunks(t_stack **a, t_stack **b, t_stack **operations,
		t_chunk *chunk)
{
	int	size;

	size = ft_lstsize(*b);
	b_to_a(a, b, operations, size - (chunk->size * (chunk->count - 1)));
	chunk->count--;
	while (chunk->count > 0)
	{
		b_to_a(a, b, operations, chunk->size);
		chunk->count--;
	}
}

int	medium(t_stack **a, t_stack **b, t_stack **operations)
{
	int		size;
	int		chunk_size;
	int		chunks;
	t_chunk	*chunk;

	size = ft_lstsize(*a);
	chunk = malloc(sizeof(t_chunk));
	if (size == 0)
		return (1);
	chunk_size = (int) ft_sqrt(size);
	if (chunk_size * chunk_size < size)
		chunk_size++;
	chunk->size = chunk_size;
	chunks = (size + chunk_size - 1) / chunk_size;
	chunk->count = chunks;
	a_to_b(a, b, operations, chunk);
	ft_chunks(a, b, operations, chunk);
	return (free(chunk), 1);
}
