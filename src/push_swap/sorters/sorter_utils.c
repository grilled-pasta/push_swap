/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:25:35 by fsalinas          #+#    #+#             */
/*   Updated: 2026/11/09 22:41:52 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ranking(t_stack **a)
{
	t_stack	*current;
	t_stack	*temp;

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
double	ft_sqrt(double n)
{
	double	x;
	int		i;

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

//checks each chunk and looks where is the max value located.
int	ft_find_max(t_stack *b, int chunk_size)
{
	int		max;
	int		i;
	int		maxpos;
	t_stack	*temp;

	if (!b || chunk_size <= 0)
		return (-1);
	i = 1;
	maxpos = 0;
	temp = b->next;
	max = b->number;
	while (i < chunk_size)
	{
		if (!temp)
			return (-1);
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
