/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 00:31:43 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/31 01:38:22 by alkonsta         ###   ########.fr       */
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

// operations
void	sa(int *a, int size);
void	sb(int *b, int size);
void	ss(int *a, int *b, int size);

#endif
