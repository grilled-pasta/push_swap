/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 18:33:36 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/09 22:27:32 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

static int	push(t_stack **s1, t_stack **s2)
{
	t_stack	*temp;

	if (!s2 || !*s2)
		return (0);
	temp = *s2;
	*s2 = (*s2)->next;
	temp->next = NULL;
	add_front(s1, temp);
	return (1);
}

void	push_a(t_stack **a, t_stack **b, t_stack **operations)
{
	if (push(a, b))
		add_operation(pa, operations);
}

void	push_b(t_stack **a, t_stack **b, t_stack **operations)
{
	if (push(b, a))
		add_operation(pb, operations);
}
