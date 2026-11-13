/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 02:56:03 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 06:28:22 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	add_operation(operation operation, stack **operations)
{
	stack	*temp;

	temp = new(operation);
	if (!temp)
		return (-1);
	add_back(operations, temp);
	return (0);
}

static int	parse_operation(char *s, stack **operations)
{
	if (ft_strncmp(s, "sa", 2) == 0)
		return (add_operation(sa, operations));
	else if (ft_strncmp(s, "sb", 2) == 0)
		return (add_operation(sb, operations));
	else if (ft_strncmp(s, "ss", 2) == 0)
		return (add_operation(ss, operations));
	else if (ft_strncmp(s, "pa", 2) == 0)
		return (add_operation(pa, operations));
	else if (ft_strncmp(s, "pb", 2) == 0)
		return (add_operation(pb, operations));
	else if (ft_strncmp(s, "ra", 2) == 0)
		return (add_operation(ra, operations));
	else if (ft_strncmp(s, "rb", 2) == 0)
		return (add_operation(rb, operations));
	else if (ft_strncmp(s, "rr", 2) == 0)
		return (add_operation(rr, operations));
	else if (ft_strncmp(s, "rra", 3) == 0)
		return (add_operation(rra, operations));
	else if (ft_strncmp(s, "rrb", 3) == 0)
		return (add_operation(rrb, operations));
	else if (ft_strncmp(s, "rrr", 3) == 0)
		return (add_operation(rrr, operations));
	return (-1);
}

static void	apply(stack **a, stack **b, stack *operations)
{
	if (operations->number == sa)
		swap_a(a, NULL);
	else if (operations->number == sb)
		swap_b(b, NULL);
	else if (operations->number == ss)
		swap_ab(a, b, NULL);
	else if (operations->number == pa)
		push_a(a, b, NULL);
	else if (operations->number == pb)
		push_b(a, b, NULL);
	else if (operations->number == ra)
		rotate_a(a, NULL);
	else if (operations->number == rb)
		rotate_b(b, NULL);
	else if (operations->number == rr)
		rotate_ab(a, b, NULL);
	else if (operations->number == rra)
		reverse_rotate_a(a, NULL);
	else if (operations->number == rrb)
		reverse_rotate_b(b, NULL);
	else if (operations->number == rrr)
		reverse_rotate_ab(a, b, NULL);
}

static void	apply_operations(stack **a, stack **b, stack *operations)
{
	while (operations)
	{
		apply(a, b, operations);
		operations = operations->next;
	}
}

int	main(int argc, char **argv)
{
	args	*args;
	char	*line;
	stack	*b;
	stack	*operations;

	operations = NULL;
	args = parse_args(argc, argv, 0);
	if (args == NULL)
		return (ft_printf_err("Error\n"), -1);
	b = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (parse_operation(line, &operations) == -1)
			return (free(line), free(operations), ft_printf_err("Error\n"), -1);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	apply_operations(&args->stack, &b, operations);
	if (is_sorted(args->stack) && (!b || ft_lstsize(b) == 0))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (clear(args->stack), free(args), free(b), clear(operations), 0);
}
