/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:19:41 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 01:07:18 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <errno.h>

static int	handle_formatter(const char **format, va_list args, int fd)
{
	t_specs	specs;

	specs = parse_specs(format, fd);
	if (!specs.specifier)
		return (-1);
	if (specs.specifier == 'c')
		return (format_c(args, specs));
	else if (specs.specifier == 's')
		return (format_s(args, specs));
	else if (specs.specifier == 'p')
		return (format_p(args, specs));
	else if (specs.specifier == 'd' || specs.specifier == 'i')
		return (format_int(args, specs));
	else if (specs.specifier == 'u')
		return (format_u(args, specs));
	else if (specs.specifier == 'x' || specs.specifier == 'X')
		return (format_x(args, specs));
	else if (specs.specifier == '%')
		return (ft_putchar('%', fd));
	return (-1);
}

static int	handle_error(int error)
{
	if (error == EOVERFLOW)
		errno = error;
	return (error);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	int		temp;

	length = 0;
	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			temp = handle_formatter(&format, args, 1);
		}
		else
			temp = ft_putchar(*format, 1);
		if (temp < 0)
			return (va_end(args), handle_error(temp));
		if (INT_MAX - length < temp)
			return (va_end(args), handle_error(EOVERFLOW));
		length += temp;
		format++;
	}
	va_end(args);
	return (length);
}

int	ft_printf_err(const char *format, ...)
{
	va_list	args;
	int		length;
	int		temp;

	length = 0;
	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			temp = handle_formatter(&format, args, 2);
		}
		else
			temp = ft_putchar(*format, 2);
		if (temp < 0)
			return (va_end(args), handle_error(temp));
		if (INT_MAX - length < temp)
			return (va_end(args), handle_error(EOVERFLOW));
		length += temp;
		format++;
	}
	va_end(args);
	return (length);
}
