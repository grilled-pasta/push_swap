/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:31:43 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/01 00:59:35 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef	struct s_stack
{
	int				number;
	struct s_stack	*next;
}				stack;

// stack
stack	*new(int number);
void	add_front(stack **s, stack *s_new);
void	add_back(stack **s, stack *s_new);
stack	*last(stack *s);
int		size(stack *s);
stack	*element(stack *s, int index);
void	iter(stack *s, void (*f)(int number));

// operations
void	sa(stack **a);
void	sb(stack **b);
void	ss(stack **a, stack **b);
void	pa(stack **a, stack **b);
void	pb(stack **a, stack **b);
void	ra(stack **a);
void	rb(stack **b);
void	rr(stack **a, stack **b);
void	rra(stack **a);
void	rrb(stack **b);
void	rrr(stack **a, stack **b);

// sortin algorithms
void	sort_selection(stack **a, stack **b);

#endif
