/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:11:23 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/26 14:39:33 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

/*
** flag[0] -> '-' flag, flag[1] -> '0' flag
** prec -> precision
** width -> field width
** spec -> converion specifier
*/

typedef struct s_flags
{
	int	flag[2];
	int	prec;
	int	width;
}				t_flags;

int		ft_printf(const char *fmt, ...);
void	ft_print_perc(const char **fmt, int *printed, t_flags *flags);
void	ft_print_str(const char **fmt, va_list ap, \
int *printed, t_flags *flags);
void	ft_print_char(const char **fmt, va_list ap, \
int *printed, t_flags *flags);
void	ft_print_lowhex(const char **fmt, va_list ap, \
int *printed, t_flags *flags);
void	ft_print_uint(const char **fmt, va_list ap, \
int *printed, t_flags *flags);
void	ft_print_ptr(const char **fmt, va_list ap, \
int *printed, t_flags *flags);
void	ft_print_uphex(const char **fmt, va_list ap, \
int *printed, t_flags *flags);
void	ft_print_int(const char **fmt, va_list ap, \
int *printed, t_flags *flags);
char	ft_set_fill_char(t_flags *flags);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_count_digit(long long n, int base);
char	ft_set_fill_char_int(t_flags *flags, int digits);
void	ft_puthex_with_prec(unsigned int num, int is_lower, int str_len);
void	ft_write_str(const char *begin, const char **fmt, int *printed);
void	ft_init_flags(t_flags *flags);
int		ft_flagtoi(char c);
void	ft_putchars(char c, int num);
void	ft_print_zero(int *printed, t_flags *flags);
void	ft_print_zero_minus(int *printed, t_flags *flags);
int		ft_get_hex_len(unsigned int num, t_flags *flags);
void	ft_putnbr_base(unsigned long long nb, char *base);
#endif
