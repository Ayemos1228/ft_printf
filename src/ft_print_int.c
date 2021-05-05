/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:09:10 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/26 14:35:58 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libc.h>

static void	ft_putnbr_with_prec(int nb, int str_len)
{
	int		digits;
	long	div;
	long	nb_copy;

	digits = ft_count_digit(nb, 10);
	div = ft_pow(10, digits - 1);
	if (nb < 0)
		div = div / 10;
	nb_copy = (long)nb;
	if (nb_copy < 0)
	{
		write(1, "-", 1);
		nb_copy *= -1;
	}
	if (str_len - digits > 0)
		ft_putchars('0', str_len - digits);
	while (div > 0)
	{
		ft_putchar(nb_copy / div + '0');
		nb_copy %= div;
		div /= 10;
	}
}

static int	ft_get_int_len(int num, t_flags *flags)
{
	int	ret;

	if (flags->prec == -1)
	{
		if (flags->flag[1] == 0)
			ret = ft_count_digit(num, 10);
		else
			ret = ft_max(flags->width, ft_count_digit(num, 10));
	}
	else if (flags->prec == 0)
		ret = ft_count_digit(num, 10);
	else
	{
		if (num > 0)
			ret = ft_max(ft_count_digit(num, 10), flags->prec);
		else
			ret = ft_max(flags->prec + 1, ft_count_digit(num, 10));
	}
	return (ret);
}

/*
**  str_len --> length of string including '-' symbol
*/

void	ft_print_int(const char **fmt, va_list ap, int *printed, t_flags *flags)
{
	int		num;
	int		str_len;

	(*fmt)++;
	num = va_arg(ap, int);
	if (num == 0 && flags->flag[0] == 1)
	{
		ft_print_zero_minus(printed, flags);
		return ;
	}
	else if (num == 0 && flags->flag[0] == 0)
	{
		ft_print_zero(printed, flags);
		return ;
	}
	str_len = ft_get_int_len(num, flags);
	if (flags->flag[0] == 1)
		ft_putnbr_with_prec(num, str_len);
	if (flags->width - str_len > 0)
		ft_putchars(' ', flags->width - str_len);
	if (flags->flag[0] == 0)
		ft_putnbr_with_prec(num, str_len);
	*printed += ft_max(str_len, flags->width);
}
