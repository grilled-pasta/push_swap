/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:47:33 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/01 01:50:29 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

float	compute_disorder(stack *s)
{
	int		mistakes;
	int		total_pairs;
	stack	*temp;

	mistakes = 0;
	total_pairs = 0;
	while (s && s->next)
	{
		temp = s->next;
		while (temp)
		{
			total_pairs += 1;
			if (s->number > temp->number)
				mistakes += 1;
			temp = temp->next;
		}
		s = s->next;
	}
	return (mistakes / (float) total_pairs);
}

static void	putnbr(int number)
{
	printf("%d\t", number);
}

static int	is_unique(stack *s, int number)
{
	while (s)
	{
		if (s->number == number)
			return (0);
		s = s->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	stack 	*a;
	stack	*b;
	stack	*temp;
	float	disorder;
	
	a = NULL;
	b = NULL;
	int i = 1;
	while (i < argc)
	{
		temp = new(atoi(argv[i]));
		if (!is_unique(a, temp->number))
			return (clear(a), clear(b), free(temp), -1);
		add_back(&a, temp);
		i++;
	}
	iter(a, putnbr);
	disorder = compute_disorder(a);
	printf("\ndisorder = %f\n\n", disorder);
	sort_selection(&a, &b);
	// printf("\nSORTED:\n");
	// iter(a, putnbr);

	// iter(b, putnbr);
	// ss(&a, &b);
	// pb(&a, &b);
	// pb(&a, &b);
	// pb(&a, &b);
	// pb(&a, &b);
	// pa(&a, &b);	
	// printf("\nStack A:\n");
	// iter(a, putnbr);
	// printf("\nStack B:\n");
	// iter(b, putnbr);
	// rrr(&a, &b);
	// printf("\nStack A:\n");
	// iter(a, putnbr);
	// printf("\nStack B:\n");
	// iter(b, putnbr);
	// rra(&a);	
	// printf("\nStack A:\n");
	// iter(a, putnbr);
	// printf("\ncompute_disorder: %f", compute_disorder(a, size(a)));
	return (clear(a), clear(b), 0);
}
