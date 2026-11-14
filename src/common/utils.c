/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:48:44 by alkonsta          #+#    #+#             */
/*   Updated: 2026/11/06 17:58:50 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (unsigned char) *s1 == (unsigned char) *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	while (n > 1 && *s1 && (unsigned char) *s1 == (unsigned char) *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	handle_sign(const char **nptr)
{	
	long	sign;

	sign = 1;
	if (**nptr == '-')
	{
		sign = -1;
		(*nptr)++;
	}
	else if (**nptr == '+')
		(*nptr)++;
	return (sign);
}

int	ft_atoi(const char *nptr, int *error)
{
	long	res;
	long	sign;
	long	limit;

	limit = INT_MAX;
	sign = handle_sign(&nptr);
	if (sign == -1)
		limit = ((long) INT_MIN) * -1;
	res = 0;
	while (*nptr == '0')
		nptr++;
	while (*nptr)
	{
		if (!is_digit(*nptr))
			return (*error = 1, 0);
		if (res > (limit - (*nptr - '0')) / 10)
			return (*error = 1, 0);
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * res);
}
