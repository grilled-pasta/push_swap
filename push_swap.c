/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:47:33 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 21:16:08 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 

void	swap(int *arr, int size)
{
	int	temp;

	temp = arr[0];
	arr[0] = arr[size - 1];
	arr[size - 1] = temp;
}

void	swap_a(int *a, int size)
{
	swap(a, size);
}

void	swap_b(int *b, int size)
{
	swap(b, size);
}

void	swap_s(int *a, int *b, int size)
{
	swap(a, size);
	swap(b, size);
}

#include <stdio.h>

float	compute_disorder(int *a, int size)
{
	int mistakes = 0;
	int	total_pairs = 0;
	int	i = 0;
	int	j;

	while (i < size - 1)
	{
		j = 1;
		while (j + i < size - 1)
		{
			total_pairs += 1;
			if (a[i] > a[j + i])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / (float) total_pairs);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	*a = malloc(sizeof(int) * (argc - 1));
	int i = 1;
	while (i < argc)
	{
		a[i - 1] = atoi(argv[i]);
		i++;
	}
	int	*b = malloc(sizeof(int) * (argc - 1));
	printf("compute_disorder: %f", compute_disorder(a, argc - 1));
}
