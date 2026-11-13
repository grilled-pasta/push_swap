/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalinas <fsalinas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:52:10 by fsalinas          #+#    #+#             */
/*   Updated: 2026/11/09 22:42:43 by fsalinas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// write a program that receive stack A as a list of integers and an optional strategy selector
// must display the smallest list of Push_swap operations possible to sort stack a
// operations separated by \n and nothing else
// the strat selction must work for all valid inputs
// no parameters == not display anything and give the prompt back
// error must display "Error\n"
// the selected strat name and complexity ust be available in --bench mode
// --bench must display: disorder (% w 2 decimal), strat name and class, total ops, count of each operation type 
// the benchmark output must be sent to stderr and only appear when the flag is present.

#include <stdarg.h>
# include "push_swap.h"


char *ft_checker(char *s, ...)
{
	va_list args;
	stack **a;
	stack **b;
	
	va_start(args, s);
	//get the numbers from argv to build stack A (Alla's parser)
	//initialize B empty; (Alla's parser)
	//Read operations from stdin (with get next line)
	//Execute each operation (use the operation identifier)
	//when EOF check that A is in order and B is empty ()
	//return KO or OK
}