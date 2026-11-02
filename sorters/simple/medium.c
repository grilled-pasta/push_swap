/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 21:25:52 by fsalinas          #+#    #+#             */
/*   Updated: 2026/11/02 21:28:37 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Still missing: function that moves content from A to B in chunks.


//this function checks each chunk and looks where is the max value located.
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

// this function checks the top chunk on stack B and sends it back to stack A in order
//Still missing: add a bigger while loop that repeats this function N times (N = amounts of chunks in B)
void b_to_a(stack **b, stack **a, int chunk_size)
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
			rb(a, b);
			i++;
		}
		pa(a, b);
		while (i > 0)
		{
			rrb(a, b);
			i--;
		}
		chunk_size--;
	}
}
