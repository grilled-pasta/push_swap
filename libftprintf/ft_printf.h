/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:20:52 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/29 00:10:52 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_flags
{
	int	left_justify;
	int	leading_zeroes;
	int	plus;
	int	space;
	int	hashtag;
}				t_flags;

typedef struct s_specs
{
	t_flags	flags;
	int		min_width;
	int		precision;
	char	specifier;
}				t_specs;

int		ft_printf(const char *format, ...);
t_specs	parse_specs(const char **format);
// formatters_char
int		format_c(va_list args, t_specs specs);
int		format_s(va_list args, t_specs specs);
// formatters_int
int		format_p(va_list args, t_specs specs);
int		format_int(va_list args, t_specs specs);
int		format_u(va_list args, t_specs specs);
int		format_x(va_list args, t_specs specs);
// formatters_spec
int		format_specs(char *s, int length, t_specs specs);
// str utils
size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putnstr(char	*s, int length);
int		ft_putnbr_base(unsigned long n, char *base, char *buffer);
// spec utils
int		calc_str_len(char *s, int length, t_specs specs);
int		print_width(int length, t_specs specs);
int		print_string(char *s, int string_length, t_specs specs);
int		sign_len(char *s);

#endif
