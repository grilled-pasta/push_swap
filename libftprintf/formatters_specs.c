/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_specs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 23:57:59 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/29 00:12:43 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_string(char *s, int lenght, t_specs specs)
{
	int	width_length;
	int	string_length;

	width_length = 0;
	string_length = lenght;
	if (specs.precision == 0 && specs.specifier != 'c')
		string_length = 0;
	if (specs.precision > 0 && specs.precision < string_length
		&& specs.specifier != 'c')
		string_length = specs.precision;
	if (specs.flags.left_justify && (specs.precision != 0
			|| specs.specifier == 'c'))
		if (ft_putnstr(s, string_length, specs.fd) < 0)
			return (-1);
	while (width_length < specs.min_width - string_length)
	{
		if (ft_putchar(' ', specs.fd) < 0)
			return (-1);
		width_length++;
	}
	if (!specs.flags.left_justify && (specs.precision != 0
			|| specs.specifier == 'c'))
		if (ft_putnstr(s, string_length, specs.fd) < 0)
			return (-1);
	return (string_length + width_length);
}

static int	format_number(char *s, int length, t_specs specs)
{
	int		width_length;
	int		result_length;

	if (s && (!*s || (specs.precision == 0 && *s == '0' && !*(s + 1))))
		length = 0;
	if (specs.flags.left_justify)
	{
		if (sign_len(s))
			if (ft_putnstr(s, sign_len(s), specs.fd) < 0)
				return (-1);
		result_length = print_string(s, length, specs);
		width_length = print_width(specs.min_width - result_length, specs);
	}
	else
	{
		result_length = calc_str_len(s, length, specs);
		if (sign_len(s) && specs.flags.leading_zeroes && specs.precision == -1)
			if (ft_putnstr(s, sign_len(s), specs.fd) < 0)
				return (-1);
		width_length = print_width(specs.min_width - result_length, specs);
		result_length = print_string(s, length, specs);
	}
	if (width_length < 0 || result_length < 0)
		return (-1);
	return (width_length + result_length);
}

int	format_specs(char *s, int length, t_specs specs)
{
	if (specs.specifier == 's' || specs.specifier == 'c')
		return (format_string(s, length, specs));
	return (format_number(s, length, specs));
}
