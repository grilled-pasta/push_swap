/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:44:46 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/07 18:31:50 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	operation_count(stack *operations, operation o)
{
	int	count;

	count = 0;
	while (operations)
	{
		if (operations->number == (int) o)
			count++;
		operations = operations->next;
	}
	return (count);
}

static void	print_strategy(char	*strategy, int adaptive)
{
	char	*s;
	char	*complexity;

	complexity = NULL;
	if (ft_strcmp(strategy, "simple") == 0)
	{
		s = "Simple";
		complexity = "𝑛²";
	}
	else if (ft_strcmp(strategy, "medium") == 0)
	{
		s = "Medium";
		complexity = "𝑛√𝑛";
	}
	else if (ft_strcmp(strategy, "complex") == 0)
	{
		s = "Complex";
		complexity = "𝑛㏒𝑛";
	}	
	if (adaptive)
		s = "Adaptive";
	ft_printf_err("%s / O(%s)\n", s, complexity);
}

void	print_benchmark(args *args, stack *operations)
{
	int	integral;
	int	decimal;

	integral = (int)(args->disorder * 100);
	decimal = (int)((args->disorder * 100 - integral) * 100);
	ft_printf_err("[bench] disorder:  %d.%d%%\n", integral, decimal);
	ft_printf_err("[bench] strategy:  ");
	print_strategy(args->strategy, args->adaptive);
	ft_printf_err("[bench] total_ops:  %d\n", ft_lstsize(operations));
	ft_printf_err("[bench] ");
	ft_printf_err("sa:  %d  ", operation_count(operations, sa));
	ft_printf_err("sb:  %d  ", operation_count(operations, sb));
	ft_printf_err("ss:  %d  ", operation_count(operations, ss));
	ft_printf_err("pa:  %d  ", operation_count(operations, pa));
	ft_printf_err("pb:  %d\n", operation_count(operations, pb));
	ft_printf_err("[bench] ");
	ft_printf_err("ra:  %d  ", operation_count(operations, ra));
	ft_printf_err("rb:  %d  ", operation_count(operations, rb));
	ft_printf_err("rr:  %d  ", operation_count(operations, rr));
	ft_printf_err("rra:  %d  ", operation_count(operations, rra));
	ft_printf_err("rrb:  %d  ", operation_count(operations, rrb));
	ft_printf_err("rrr:  %d\n", operation_count(operations, rrr));
}
