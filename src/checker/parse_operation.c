/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:35:00 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 09:42:25 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

static int	add_operation(t_operation operation, t_stack **operations)
{
	t_stack	*temp;

	temp = new(operation);
	if (!temp)
		return (-1);
	add_back(operations, temp);
	return (0);
}

int	parse_operation(char *s, t_stack **operations)
{
	if (ft_strcmp(s, "sa") == 0)
		return (add_operation(sa, operations));
	else if (ft_strcmp(s, "sb") == 0)
		return (add_operation(sb, operations));
	else if (ft_strcmp(s, "ss") == 0)
		return (add_operation(ss, operations));
	else if (ft_strcmp(s, "pa") == 0)
		return (add_operation(pa, operations));
	else if (ft_strcmp(s, "pb") == 0)
		return (add_operation(pb, operations));
	else if (ft_strcmp(s, "ra") == 0)
		return (add_operation(ra, operations));
	else if (ft_strcmp(s, "rb") == 0)
		return (add_operation(rb, operations));
	else if (ft_strcmp(s, "rr") == 0)
		return (add_operation(rr, operations));
	else if (ft_strcmp(s, "rra") == 0)
		return (add_operation(rra, operations));
	else if (ft_strcmp(s, "rrb") == 0)
		return (add_operation(rrb, operations));
	else if (ft_strcmp(s, "rrr") == 0)
		return (add_operation(rrr, operations));
	return (-1);
}

void	apply_operation(t_stack **a, t_stack **b, int number)
{
	if (number == sa)
		swap_a(a, NULL);
	else if (number == sb)
		swap_b(b, NULL);
	else if (number == ss)
		swap_ab(a, b, NULL);
	else if (number == pa)
		push_a(a, b, NULL);
	else if (number == pb)
		push_b(a, b, NULL);
	else if (number == ra)
		rotate_a(a, NULL);
	else if (number == rb)
		rotate_b(b, NULL);
	else if (number == rr)
		rotate_ab(a, b, NULL);
	else if (number == rra)
		reverse_rotate_a(a, NULL);
	else if (number == rrb)
		reverse_rotate_b(b, NULL);
	else if (number == rrr)
		reverse_rotate_ab(a, b, NULL);
}
