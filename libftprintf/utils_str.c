/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 22:29:31 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 01:08:09 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s && s[length])
		length++;
	return (length);
}

int	ft_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putnstr(char	*s, int length, int fd)
{
	return (write(fd, s, length));
}

int	ft_putnbr_base(unsigned long n, char *base, char *buffer)
{
	int		length;
	size_t	base_length;
	int		res;

	length = 0;
	res = 0;
	if (!base || ft_strlen(base) < 2 || !buffer)
		return (-1);
	base_length = ft_strlen(base);
	if (n >= base_length)
	{
		res = ft_putnbr_base(n / base_length, base, buffer);
		if (res < 0)
			return (res);
		length = res;
	}
	buffer[length] = base[n % base_length];
	return (length + 1);
}
