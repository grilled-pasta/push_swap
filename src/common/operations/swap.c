/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:22:10 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/09 22:27:07 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	swap(t_stack **s)
{
	t_stack	*s1;
	t_stack	*s2;

	if (!s || !*s || !(*s)->next)
		return (0);
	s1 = *s;
	s2 = s1->next;
	s1->next = s2->next;
	s2->next = s1;
	*s = s2;
	return (1);
}

void	swap_a(t_stack **a, t_stack **operations)
{
	if (swap(a))
		add_operation(sa, operations);
}

void	swap_b(t_stack **b, t_stack **operations)
{
	if (swap(b))
		add_operation(sa, operations);
}

void	swap_ab(t_stack **a, t_stack **b, t_stack **operations)
{
	int	sa_res;
	int	sb_res;

	sa_res = swap(a);
	sb_res = swap(b);
	if (sa_res && sb_res)
		add_operation(ss, operations);
	else if (sa_res)
		add_operation(sa, operations);
	else if (sb_res)
		add_operation(sb, operations);
}
