/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:22:10 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/31 00:34:03 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *arr, int size)
{
	int	temp;

	temp = arr[0];
	arr[0] = arr[size - 1];
	arr[size - 1] = temp;
}

void	sa(int *a, int size)
{
	swap(a, size);
}

void	sb(int *b, int size)
{
	swap(b, size);
}

void	ss(int *a, int *b, int size)
{
	swap(a, size);
	swap(b, size);
}
