/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:22:10 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 21:25:51 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
