/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:11:40 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/24 22:13:31 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_str_minus(char *str, int *printed, t_flags *flags)
{
	int		str_len;
	char	fill_char;
	int		idx;

	str_len = ft_min(flags->prec, ft_strlen(str));
	if (flags->prec == -1)
		str_len = ft_strlen(str);
	fill_char = ft_set_fill_char(flags);
	idx = 0;
	write(1, str, str_len);
	while (idx < flags->width - str_len)
	{
		write(1, &fill_char, 1);
		idx++;
	}
	*printed += ft_max(str_len, flags->width);
}

void	ft_print_str(const char **fmt, va_list ap, int *printed, t_flags *flags)
{
	int		str_len;
	char	*str;
	char	fill_char;
	int		idx;

	(*fmt)++;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (flags->flag[0])
	{
		ft_print_str_minus(str, printed, flags);
		return ;
	}
	str_len = ft_min(flags->prec, ft_strlen(str));
	if (flags->prec == -1)
		str_len = ft_strlen(str);
	fill_char = ft_set_fill_char(flags);
	idx = 0;
	while (idx++ < flags->width - str_len)
		write(1, &fill_char, 1);
	write(1, str, str_len);
	*printed += ft_max(str_len, flags->width);
}
