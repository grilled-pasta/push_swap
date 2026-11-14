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

static t_stack	*parse_operations(int *error)
{
	char	*line;
	t_stack	*operations;

	operations = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (line[ft_strlen(line) - 1] != '\n')
			return (*error = 1, free(line), clear(operations), NULL);
		line[ft_strlen(line) - 1] = '\0';
		if (parse_operation(line, &operations) == -1)
			return (*error = 1, free(line), clear(operations), NULL);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (operations);
}

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
	t_stack	*a;
	t_stack	*b;
	t_stack	*operations;
	int		error;

	error = 0;
	a = parse_stack(1, argc, argv);
	if (a == NULL)
		return (ft_printf_err("Error\n"), -1);
	b = NULL;
	operations = parse_operations(&error);
	if (error)
		return (clear(a), ft_printf_err("Error\n"), -1);
	apply_operations(&a, &b, operations);
	if (is_sorted(a) && (!b || ft_lstsize(b) == 0))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (clear(a), clear(b), clear(operations), 0);
}
