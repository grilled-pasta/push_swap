/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:11:59 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 03:40:28 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_p(va_list args, t_specs specs)
{
	void	*temp;
	int		length;
	char	buffer[67];
	int		sign;

	temp = va_arg(args, void *);
	sign = 2;
	if (!temp)
		return (format_specs("(nil)", 5, specs));
	buffer[0] = '0';
	buffer[1] = 'x';
	length = ft_putnbr_base((unsigned long) temp, "0123456789abcdef", buffer
			+ sign);
	if (length < 0)
		return (-1);
	buffer[length + sign] = '\0';
	return (format_specs(buffer, ft_strlen(buffer), specs));
}

int	format_int(va_list args, t_specs specs)
{
	int		temp;
	long	n;
	int		length;
	int		sign;
	char	buffer[12];

	temp = va_arg(args, int);
	n = temp;
	sign = (n < 0 || specs.flags.plus || specs.flags.space);
	if (n == 0 && specs.precision == 0)
		return (buffer[0] = '\0', format_specs(buffer, 0, specs));
	if (n < 0)
	{
		buffer[0] = '-';
		n = -n;
	}
	else if (specs.flags.plus)
		buffer[0] = '+';
	else if (specs.flags.space)
		buffer[0] = ' ';
	length = ft_putnbr_base(n, "0123456789", buffer + sign);
	if (length < 0)
		return (-1);
	buffer[length + sign] = '\0';
	return (format_specs(buffer, ft_strlen(buffer), specs));
}

int	format_u(va_list args, t_specs specs)
{
	unsigned int	temp;
	int				length;
	char			buffer[11];

	temp = va_arg(args, unsigned int);
	length = ft_putnbr_base(temp, "0123456789", buffer);
	if (length < 0)
		return (-1);
	buffer[length] = '\0';
	return (format_specs(buffer, ft_strlen(buffer), specs));
}

int	format_x(va_list args, t_specs specs)
{
	long			temp;
	char			*base;
	int				length;
	char			buffer[14];
	int				sign;

	temp = (long) va_arg(args, unsigned int);
	sign = 0;
	if (specs.specifier == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (specs.flags.hashtag && temp)
	{
		buffer[0] = '0';
		buffer[1] = specs.specifier;
		sign += 2;
	}
	length = ft_putnbr_base(temp, base, buffer + sign);
	if (length < 0)
		return (-1);
	buffer[length + sign] = '\0';
	return (format_specs(buffer, ft_strlen(buffer), specs));
}
