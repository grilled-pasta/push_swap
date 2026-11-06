/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:47:33 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/06 17:58:48 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

static void	putnbr(int number)
{
	char	*operation;

	if (number == sa)
		operation = "sa";
	else if (number == sb)
		operation = "sb";
	else if (number == ss)
		operation = "ss";
	else if (number == pa)
		operation = "pa";
	else if (number == pb)
		operation = "pb";
	else if (number == ra)
		operation = "ra";
	else if (number == rb)
		operation = "rb";
	else if (number == rr)
		operation = "rr";
	else if (number == rra)
		operation = "rra";
	else if (number == rrb)
		operation = "rrb";
	else
		operation = "rrr";
	ft_printf("%s\n", operation);
}

void	sort(args *args, stack **operations)
{
	stack	*temp;
	
	temp = NULL;
	if (ft_strcmp(args->strategy, "simple") == 0)
		simple(&args->stack, &temp, operations);
	else if (ft_strcmp(args->strategy, "medium") == 0)
		medium(&args->stack, &temp, operations);
	else if (ft_strcmp(args->strategy, "complex") == 0)
		complex(&args->stack, &temp, operations);
	else if (ft_strcmp(args->strategy, "adaptive") == 0)
	{
		if (args->disorder <= 0.2)
			simple(&args->stack, &temp, operations);
		else if (args->disorder <= 0.5)
			medium(&args->stack, &temp, operations);
		else
			complex(&args->stack, &temp, operations);
	}
	clear(temp);
}

void	putn(int number)
{
	ft_printf("%d\t", number);
}

int	main(int argc, char **argv)
{
	args	*args;
	stack	*operations;

	args = parse_args(argc, argv);
	operations = NULL;
	if (args == NULL)
	{
		if (args != NULL && args->stack != NULL)
			clear(args->stack);
		return (0);
	}
	// iter(args->stack, putn);
	sort(args, &operations);
	iter(operations, putnbr);
	// iter(args->stack, putn);
	// printf("\noperations: %d\n", ft_lstsize(operations));
	return (clear(args->stack), free(args), clear(operations), 0);
}
