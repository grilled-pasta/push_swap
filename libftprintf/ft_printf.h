/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkonsta <alkonsta@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:20:52 by alkonsta          #+#    #+#             */
/*   Updated: 2026/10/24 03:39:07 by alkonsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE_10	"0123456789"
# define BASE_16_L	"0123456789abcdef"
# define BASE_16_U	"0123456789ABCDEF"

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	left_justify;	// - left justify (right is default)
	int	leading_zeroes; // 0 only int, ignored is left_justify present or for
						// ints if precision is specified
	int	plus; 			// + only signed int, ignored by others
	int	space;
	int	hashtag;		// # alternative conversion, only non-decimal integer
}				t_flags;

typedef struct	s_specs
{
	t_flags	flags;
	int		min_width; // int or '*' padded with space chars
	int		precision; // .(int or *) default is 0, negative is ignored
	int		length;    // size of the argument?
	char	specifier; // the format used, if invalid => undefined
}				t_specs;

int		ft_printf(const char *format, ...);
// str_utils
size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putstr(char	*s);
int		ft_putnstr(char	*s, int length);
int		ft_putnbr_base(unsigned long n, char *base, char *buffer);
// formatters_char 
int		format_c(va_list args, t_specs specs);
int		format_s(va_list args, t_specs specs);
// formatters_int
int		format_p(va_list args, t_specs specs);
int		format_int(va_list args, t_specs specs);
int		format_u(va_list args, t_specs specs);
int		format_x(va_list args, char format, t_specs specs);
// specs
t_specs	parse_specs(const char **format);
// formatters_spec
int		format_specs(char *s, int length, t_specs specs);

#endif
