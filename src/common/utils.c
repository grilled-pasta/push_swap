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

int	ft_atoi(const char *nptr)
{
	long	res;
	long	sign;

	sign = 1;
	if (ft_strcmp((char *) nptr, "-2147483648") == 0)
		return (-2147483648);
	if (*nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	res = 0;
	while (*nptr)
	{
		if (!is_digit(*nptr))
			return (0);
		res = res * 10 + (*nptr - '0');
		if ((sign == -1 && (res * sign) < INT_MIN) || res > INT_MAX)
			return (0);
		nptr++;
	}
	return (sign * res);
}
