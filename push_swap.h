/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:31:43 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/05 15:26:55 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef	struct	s_stack
{
	int				number;
	int				rank;
	struct s_stack	*next;
}				stack;

typedef struct	s_args
{
	char	*strategy;
	stack	*stack;
	float	disorder;
}				args;

// stack
stack	*new(int number);
void	add_front(stack **s, stack *s_new);
void	add_back(stack **s, stack *s_new);
stack	*last(stack *s);
int		size(stack *s);
stack	*element(stack *s, int index);
void	iter(stack *s, void (*f)(int number));
void	clear(stack *s);
// utils
float	compute_disorder(stack *s);
// parser
args	*parse_args(int argc, char **argv);
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

// sorting algorithms
void	sort_simple_selection(stack **a, stack **b);

#endif
