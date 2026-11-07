/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 00:52:53 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 03:47:36 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(va_list args, t_specs specs)
{
	char	temp;
	char	str[2];

	temp = (unsigned char) va_arg(args, int);
	str[0] = temp;
	str[1] = '\0';
	return (format_specs(str, 1, specs));
}

int	format_s(va_list args, t_specs specs)
{
	char	*temp;

	temp = (char *) va_arg(args, char *);
	if (!temp)
	{
		if (specs.precision >= 0 && specs.precision < 6)
			temp = "";
		else
			temp = "(null)";
	}
	return (format_specs(temp, ft_strlen(temp), specs));
}
