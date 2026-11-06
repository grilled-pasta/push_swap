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

enum Operation {sa, sb, ss, pa, pb, ra, rb ,rr, rra, rrb, rrr};

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
int		ft_lstsize(stack *s);
stack	*element(stack *s, int index);
void	iter(stack *s, void (*f)(int number));
void	clear(stack *s);
// utils
float	compute_disorder(stack *s);
// parser
args	*parse_args(int argc, char **argv);
// operations
void	swap_a(stack **a, stack **operations);
void	swap_b(stack **b, stack **operations);
void	swap_ab(stack **a, stack **b, stack **operations);
void	push_a(stack **a, stack **b, stack **operations);
void	push_b(stack **a, stack **b, stack **operations);
void	rotate_a(stack **a, stack **operations);
void	rotate_b(stack **b, stack **operations);
void	rotate_ab(stack **a, stack **b, stack **operations);
void	reverse_rotate_a(stack **a, stack **operations);
void	reverse_rotate_b(stack **b, stack **operations);
void	reverse_rotate_ab(stack **a, stack **b, stack **operations);

// sorting algorithms
void	simple(stack **a, stack **b, stack **operations);
int 	medium(stack **a, stack **b, stack **operations);
int 	complex(stack **a, stack **b, stack **operations);

#endif
