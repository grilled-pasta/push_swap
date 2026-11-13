/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:31:43 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 07:08:55 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libftprintf/ft_printf.h"

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

typedef struct s_chunk
{
	int	size;
	int	index;
	int	remaining;
}	t_chunk;

// t_stack
t_stack	*new(int number);
void	add_front(t_stack **s, t_stack *s_new);
void	add_back(t_stack **s, t_stack *s_new);
t_stack	*last(t_stack *s);
int		ft_lstsize(t_stack *s);
void	iter(t_stack *s, void (*f)(int number));
void	clear(t_stack *s);
// utils
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
// sorting algorithms
void	simple(t_stack **a, t_stack **b, t_stack **operations);
int		medium(t_stack **a, t_stack **b, t_stack **operations);
int		complex(t_stack **a, t_stack **b, t_stack **operations);
// benchmark
void	print_benchmark(t_args *t_args, t_stack *operations);
// sorter_utils
void	ft_ranking(t_stack **a);
double	ft_sqrt(double n);
int		ft_is_sorted(t_stack *a);
int		ft_find_max(t_stack *b, int chunk_size);
// parser_utils
float	compute_disorder(t_stack *s);
int		is_number(char *s);
int		is_strategy(char *arg);
int		is_unique(t_stack *s, int number);

#endif
