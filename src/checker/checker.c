/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 02:56:03 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 09:38:57 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "ft_printf.h"
#include "get_next_line.h"

static void	apply_operations(t_stack **a, t_stack **b, t_stack *operations)
{
	while (operations)
	{
		apply_operation(a, b, operations->number);
		operations = operations->next;
	}
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;
	t_stack	*operations;

	operations = NULL;
	a = parse_stack(1, argc, argv);
	if (a == NULL)
		return (ft_printf_err("Error\n"), -1);
	b = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (line[ft_strlen(line) - 1] != '\n')
			return (free(line), clear(operations),
				ft_printf_err("Error\n"), -1);
		line[ft_strlen(line) - 1] = '\0';
		if (parse_operation(line, &operations) == -1)
			return (free(line), clear(operations),
				ft_printf_err("Error\n"), -1);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	apply_operations(&a, &b, operations);
	if (is_sorted(a) && (!b || ft_lstsize(b) == 0))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (clear(a), clear(b), clear(operations), 0);
}
