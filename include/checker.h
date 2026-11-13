/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 06:07:29 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/13 09:49:01 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

// parser
int		parse_operation(char *s, t_stack **operations);
void	apply_operation(t_stack **a, t_stack **b, int number);

#endif
