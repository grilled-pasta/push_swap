/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 00:11:39 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/01 01:58:09 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"

static int	rotate(t_stack **s)
{
	t_stack	*temp;

	if (!s || !*s || !(*s)->next)
		return (0);
	temp = *s;
	last(*s)->next = *s;
	*s = temp->next;
	temp->next = NULL;
	return (1);
}

void	rotate_a(t_stack **a, t_stack **operations)
{
	if (rotate(a))
		add_operation(ra, operations);
}

void	rotate_b(t_stack **b, t_stack **operations)
{
	if (rotate(b))
		add_operation(rb, operations);
}

void	rotate_ab(t_stack **a, t_stack **b, t_stack **operations)
{
	int	ra_res;
	int	rb_res;

	ra_res = rotate(a);
	rb_res = rotate(b);
	if (ra_res && rb_res)
		add_operation(rr, operations);
	else if (ra_res)
		add_operation(ra, operations);
	else if (rb_res)
		add_operation(rb, operations);
}
