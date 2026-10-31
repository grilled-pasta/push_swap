/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:47:33 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/01 00:32:13 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

float	compute_disorder(stack *s, int size)
{
	int mistakes = 0;
	int	total_pairs = 0;
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 1;
		while (j + i < size)
		{
			total_pairs += 1;
			if (s->number > element(s, i + j)->number)
				mistakes += 1;
			j++;
		}
		i++;
		s = s->next;
	}
	return (mistakes / (float) total_pairs);
}

static void	putnbr(int number)
{
	printf("%d\t", number);
}

int	main(int argc, char **argv)
{
	stack 	*a;
	stack	*b;
	stack	*temp;
	
	a = NULL;
	b = NULL;
	int i = 1;
	while (i < argc)
	{
		temp = new(atoi(argv[i]));
		add_back(&a, temp);
		i++;
	}
	ss(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pa(&a, &b);	
	printf("\nStack A:\n");
	iter(a, putnbr);
	printf("\nStack B:\n");
	iter(b, putnbr);
	rrr(&a, &b);
	printf("\nStack A:\n");
	iter(a, putnbr);
	printf("\nStack B:\n");
	iter(b, putnbr);
	rra(&a);	
	printf("\nStack A:\n");
	iter(a, putnbr);
	printf("\ncompute_disorder: %f", compute_disorder(a, size(a)));
}
