/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 20:47:33 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 08:49:01 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "common.h"
#include "ft_printf.h"

static void	put_operations(int number)
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

void	sort(t_args *args, t_stack **operations)
{
	t_stack	*temp;

	temp = NULL;
	if (ft_strcmp(args->strategy, "simple") == 0)
		simple(&args->stack, &temp, operations);
	else if (ft_strcmp(args->strategy, "medium") == 0)
		medium(&args->stack, &temp, operations);
	else if (ft_strcmp(args->strategy, "complex") == 0)
		complex(&args->stack, &temp, operations);
	clear(temp);
}

int	main(int argc, char **argv)
{
	t_args	*args;
	t_stack	*operations;

	if (argc < 2)
		return (0);
	args = parse_args(argc, argv);
	operations = NULL;
	if (args == NULL)
		return (ft_printf_err("Error\n"), -1);
	else if (args->stack == NULL)
		return (free(args), 0);
	if (!is_sorted(args->stack))
	{
		sort(args, &operations);
		// if (args->benchmark)
		// 	print_benchmark(args, operations);
		iter(operations, put_operations);
	}		
	if (args->benchmark)
		print_benchmark(args, operations);
	return (clear(args->stack), free(args), clear(operations), 0);
}
