/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 00:23:24 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/09 22:26:58 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

static int	reverse_rotate(t_stack **s)
{
	t_stack	*s_temp;
	t_stack	*s_last;

	if (!s || !*s || !(*s)->next)
		return (0);
	s_temp = *s;
	while (s_temp->next->next != NULL)
		s_temp = s_temp->next;
	s_last = s_temp->next;
	s_last->next = *s;
	s_temp->next = NULL;
	*s = s_last;
	return (1);
}

void	reverse_rotate_a(t_stack **a, t_stack **operations)
{
	if (reverse_rotate(a))
		add_operation(rra, operations);
}

void	reverse_rotate_b(t_stack **b, t_stack **operations)
{
	if (reverse_rotate(b))
		add_operation(rrb, operations);
}

void	reverse_rotate_ab(t_stack **a, t_stack **b, t_stack **operations)
{
	int	rra_res;
	int	rrb_res;

	rra_res = reverse_rotate(a);
	rrb_res = reverse_rotate(b);
	if (rra_res && rrb_res)
		add_operation(rrr, operations);
	else if (rra_res)
		add_operation(rra, operations);
	else if (rrb_res)
		add_operation(rrb, operations);
}
