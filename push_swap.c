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
#include "libftprintf/ft_printf.h"

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

static int	is_sorted(stack *s)
{
	int	prev;

	if (!s)
		return (1);
	prev = s->number;
	s = s->next;
	while (s)
	{
		if (s->number < prev)
			return (0);
		prev = s->number;
		s = s->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	args	*args;
	stack	*operations;

	args = parse_args(argc, argv);
	operations = NULL;
	if (args == NULL)
		return (-1);
	if (!is_sorted(args->stack))
	{
		sort(args, &operations);
		iter(operations, put_operations);
	}
	return (clear(args->stack), free(args), clear(operations), 0);
}
