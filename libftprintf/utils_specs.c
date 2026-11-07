/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_specs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 21:58:11 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/29 00:10:40 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sign_len(char *s)
{
	if (*s == '0' && *(s + 1) && (*(s + 1) == 'x' || *(s + 1) == 'X'))
		return (2);
	return (*s == '-' || *s == '+' || *s == ' ');
}

int	calc_str_len(char *s, int length, t_specs specs)
{
	int	result_length;
	int	sign;

	result_length = 0;
	sign = sign_len(s);
	if (specs.precision > length - sign)
		result_length += specs.precision - length + sign;
	result_length += length;
	return (result_length);
}

int	print_width(int length, t_specs specs)
{
	int		width_length;
	char	width_c;

	width_length = 0;
	width_c = ' ';
	if (specs.precision > 0)
		specs.flags.leading_zeroes = 0;
	if (specs.flags.leading_zeroes && specs.precision == -1)
		width_c = '0';
	while (width_length < length)
	{
		if (ft_putchar(width_c, specs.fd) < 0)
			return (-1);
		width_length++;
	}
	return (width_length);
}

int	print_string(char *s, int string_length, t_specs specs)
{
	int	length;
	int	zeroes;
	int	sign;

	zeroes = 0;
	sign = sign_len(s);
	if (sign && !(specs.flags.leading_zeroes && specs.precision == -1)
		&& !specs.flags.left_justify)
		if (ft_putnstr(s, sign, specs.fd) < 0)
			return (-1);
	if (specs.precision > string_length - sign)
	{
		while (zeroes < specs.precision - string_length + sign)
		{
			if (ft_putchar('0', specs.fd) < 0)
				return (-1);
			zeroes++;
		}
	}
	length = ft_putnstr(s + sign, string_length - sign, specs.fd);
	if (length < 0)
		return (-1);
	return (length + zeroes + sign);
}
