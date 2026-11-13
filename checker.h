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

typedef enum e_operation
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}			t_operation;

typedef struct s_stack
{
	int				number;
	int				rank;
	struct s_stack	*next;
}				t_stack;

typedef struct s_args
{
	char	*strategy;
	t_stack	*stack;
	float	disorder;
	int		benchmark;
	int		adaptive;
}				t_args;

// t_stack
t_stack	*new(int number);
void	add_front(t_stack **s, t_stack *s_new);
void	add_back(t_stack **s, t_stack *s_new);
t_stack	*last(t_stack *s);
int		ft_lstsize(t_stack *s);
void	iter(t_stack *s, void (*f)(int number));
void	clear(t_stack *s);
// utils
float	compute_disorder(t_stack *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
int		is_digit(char c);
int		ft_atoi(const char *nptr);
int		is_sorted(t_stack *s);
// parser
t_args	*parse_args(int argc, char **argv, int has_flags);
// operations
void	swap_a(t_stack **a, t_stack **operations);
void	swap_b(t_stack **b, t_stack **operations);
void	swap_ab(t_stack **a, t_stack **b, t_stack **operations);
void	push_a(t_stack **a, t_stack **b, t_stack **operations);
void	push_b(t_stack **a, t_stack **b, t_stack **operations);
void	rotate_a(t_stack **a, t_stack **operations);
void	rotate_b(t_stack **b, t_stack **operations);
void	rotate_ab(t_stack **a, t_stack **b, t_stack **operations);
void	reverse_rotate_a(t_stack **a, t_stack **operations);
void	reverse_rotate_b(t_stack **b, t_stack **operations);
void	reverse_rotate_ab(t_stack **a, t_stack **b, t_stack **operations);
// parser_utils
float	compute_disorder(t_stack *s);
int		is_number(char *s);
int		is_strategy(char *arg);
int		is_unique(t_stack *s, int number);
t_stack	*parse_stack(int i, int argc, char **argv);

#endif
