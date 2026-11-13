/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:31:43 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 08:53:58 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

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

// parser
t_args	*parse_args(int argc, char **argv);
// sorting algorithms
void	simple(t_stack **a, t_stack **b, t_stack **operations);
int		medium(t_stack **a, t_stack **b, t_stack **operations);
int		complex(t_stack **a, t_stack **b, t_stack **operations);
// benchmark
void	print_benchmark(t_args *t_args, t_stack *operations);
// sorter_utils
void	ft_ranking(t_stack **a);
double	ft_sqrt(double n);
int		ft_find_max(t_stack *b, int chunk_size);

#endif
