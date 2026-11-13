/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:31:43 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 06:45:20 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libftprintf/ft_printf.h"

typedef enum e_operation {
	sa, sb, ss, pa, pb, ra, rb ,rr, rra, rrb, rrr
}			operation;

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

typedef struct s_chunk
{
	int	size;
	int	index;
	int	remaining;
}	t_chunk;

// stack
stack	*new(int number);
void	add_front(stack **s, stack *s_new);
void	add_back(stack **s, stack *s_new);
stack	*last(stack *s);
int		ft_lstsize(stack *s);
void	iter(stack *s, void (*f)(int number));
void	clear(stack *s);
// utils
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
// sorting algorithms
void	simple(stack **a, stack **b, stack **operations);
int 	medium(stack **a, stack **b, stack **operations);
int 	complex(stack **a, stack **b, stack **operations);
// benchmark
void	print_benchmark(args *args, stack *operations);
// sorter_utils
void	ft_ranking(stack **a);
double	ft_sqrt(double n);
int		ft_is_sorted(stack *a);
int		ft_find_max(stack *b, int chunk_size);
// parser_utils
float	compute_disorder(stack *s);
int		is_number(char *s);
int		is_strategy(char *arg);
int		is_unique(stack *s, int number);

#endif
