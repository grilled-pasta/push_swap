/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:47:33 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/31 01:42:53 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> 
#include <stdio.h>

float	compute_disorder(stack *s, int size)
{
	int mistakes = 0;
	int	total_pairs = 0;
	int	i = 0;
	int	j;

	while (s && i < size - 1)
	{
		j = 1;
		while (j + i < size - 1)
		{
			total_pairs += 1;
			printf("\ni=%d)s->number=%d, element(s, %d)=%d\n", i, s->number, i + j, element(s, i+j)->number);
			if (s->number > element(s, i + j)->number)
			{
				mistakes += 1;
			}
			j++;
		}
		i++;
		s = s->next;
	}
	return (mistakes / (float) total_pairs);
}

int	main(int argc, char **argv)
{
	stack 	*s;
	stack	*temp;
	
	s = NULL;
	int i = 1;
	while (i < argc)
	{
		temp = new(atoi(argv[i]));
		add_back(&s, temp);
		i++;
	}
	// while (s && s->next)
	// {
	// 	printf("%d\t", s->number);
	// 	s = s->next;
	// }		
	// printf("%d\t", s->number);
	printf("\nsize: %d\n", size(s));
	printf("\ncompute_disorder: %f", compute_disorder(s, size(s)));
}
