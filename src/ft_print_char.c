/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:08:20 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/26 14:17:44 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_char_minus(va_list ap, int *printed, t_flags *flags)
{
	unsigned char	c;
	int				idx;

	c = (unsigned char)va_arg(ap, int);
	idx = 0;
	write(1, &c, 1);
	while (idx < flags->width - 1)
	{
		write(1, " ", 1);
		idx++;
	}
	if (flags->width == -1)
		*printed += 1;
	else
		*printed += flags->width;
}

void	ft_print_char(const char **fmt, va_list ap, \
int *printed, t_flags *flags)
{
	unsigned char	c;
	char			fill_char;
	int				idx;

	(*fmt)++;
	if (flags->flag[0])
	{
		ft_print_char_minus(ap, printed, flags);
		return ;
	}
	c = (unsigned char)va_arg(ap, int);
	fill_char = ft_set_fill_char(flags);
	idx = 0;
	while (idx < flags->width - 1)
	{
		write(1, &fill_char, 1);
		idx++;
	}
	write(1, &c, 1);
	if (flags->width == -1)
		*printed += 1;
	else
		*printed += flags->width;
}
