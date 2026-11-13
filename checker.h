/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 06:07:29 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 06:57:58 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "libftprintf/ft_printf.h"
# include "get_next_line/get_next_line.h"

typedef enum e_operation {
	sa, sb, ss, pa, pb, ra, rb ,rr, rra, rrb, rrr
}		operation;

typedef struct	s_stack
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
	int		benchmark;
	int		adaptive;
}				args;

// stack
stack	*new(int number);
void	add_front(stack **s, stack *s_new);
void	add_back(stack **s, stack *s_new);
stack	*last(stack *s);
int		ft_lstsize(stack *s);
void	iter(stack *s, void (*f)(int number));
void	clear(stack *s);
// utils
float	compute_disorder(stack *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
int		is_digit(char c);
int		ft_atoi(const char *nptr);
int		is_sorted(stack *s);
// parser
args	*parse_args(int argc, char **argv, int has_flags);
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
// parser_utils
float	compute_disorder(stack *s);
int		is_number(char *s);
int		is_strategy(char *arg);
int		is_unique(stack *s, int number);
stack	*parse_stack(int i, int argc, char **argv);

#endif
