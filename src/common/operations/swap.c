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

static void	swap(t_stack **s)
{
	t_stack	*s1;
	t_stack	*s2;

	if (!s || !*s || !(*s)->next)
		return ;
	s1 = *s;
	s2 = s1->next;
	s1->next = s2->next;
	s2->next = s1;
	*s = s2;
}

void	swap_a(t_stack **a, t_stack **operations)
{
	swap(a);
	add_back(operations, new(sa));
}

void	swap_b(t_stack **b, t_stack **operations)
{
	swap(b);
	add_back(operations, new(sb));
}

void	swap_ab(t_stack **a, t_stack **b, t_stack **operations)
{
	swap(a);
	swap(b);
	add_back(operations, new(ss));
}
