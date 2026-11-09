/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:25:35 by fsalinas          #+#    #+#             */
/*   Updated: 2026/11/09 17:29:04 by fsalinas         ###   ########.fr       */
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

//This one should go in the function that decides what algorithm is better to use
int	ft_is_sorted(stack *a)
{
	while (a && a->next)
	{
		if (a->number > a->next->number)
			return (0);
		a = a->next;
	}
	return (1);
}