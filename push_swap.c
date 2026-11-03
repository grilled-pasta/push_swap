/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:47:33 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/03 17:47:59 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	putnbr(int number)
{
	printf("%d\t", number);
}

int	main(int argc, char **argv)
{
	args	*args;
	stack	*temp;

	args = parse_args(argc, argv);
	temp = NULL;
	iter(args->stack, putnbr);
	printf("\ndisorder = %.2f\n\n", args->disorder);
	if (strcmp(args->strategy, "simple") == 0
		|| strcmp(args->strategy, "adaptive") == 0)
		sort_simple_selection(&args->stack, &temp);
	printf("\n\n");
	iter(args->stack, putnbr);
	return (clear(args->stack), free(args), clear(temp), 0);
}
