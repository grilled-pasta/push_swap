/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 23:53:07 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/28 23:59:50 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#');
}

static t_flags	parse_flags(const char **format)
{
	t_flags	flags;

	flags.left_justify = 0;
	flags.leading_zeroes = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.hashtag = 0;
	while (**format && is_flag(**format))
	{
		if (**format == '-')
			flags.left_justify = 1;
		else if (**format == '0')
			flags.leading_zeroes = 1;
		else if (**format == '+')
			flags.plus = 1;
		else if (**format == ' ')
			flags.space = 1;
		else if (**format == '#')
			flags.hashtag = 1;
		(*format)++;
	}
	return (flags);
}

static int	ft_isspec(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int	parse_number(const char **format)
{
	int	width;
	int	digit;

	width = 0;
	while (**format && (**format >= '0' && **format <= '9'))
	{
		digit = (**format - '0');
		if (width > (INT_MAX - digit) / 10)
			return (-1);
		width = width * 10 + digit;
		(*format)++;
	}
	return (width);
}

t_specs	parse_specs(const char **format, int fd)
{
	t_specs	specs;
	t_flags	flags;

	flags = parse_flags(format);
	specs.flags = flags;
	specs.min_width = parse_number(format);
	specs.precision = -1;
	specs.specifier = '\0';
	specs.fd = fd;
	if (specs.min_width < 0)
		return (specs);
	if (**format == '.')
	{
		(*format)++;
		specs.precision = parse_number(format);
		if (specs.precision < 0)
			return (specs);
	}
	if (**format && ft_isspec(**format))
		specs.specifier = **format;
	return (specs);
}
