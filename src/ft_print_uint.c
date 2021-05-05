/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:09:37 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/26 14:33:05 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putuint_with_prec(unsigned int nb, int str_len)
{
	int	digits;
	int	div;

	digits = ft_count_digit(nb, 10);
	div = ft_pow(10, digits - 1);
	if (str_len - digits > 0)
		ft_putchars('0', str_len - digits);
	while (div > 0)
	{
		ft_putchar(nb / div + '0');
		nb %= div;
		div /= 10;
	}
}

static int	ft_get_uint_len(unsigned int num, t_flags *flags)
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

void	ft_print_uint(const char **fmt, va_list ap, \
int *printed, t_flags *flags)
{
	unsigned int	num;
	int				str_len;

	(*fmt)++;
	num = va_arg(ap, unsigned int);
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
	str_len = ft_get_uint_len(num, flags);
	if (flags->flag[0] == 1)
		ft_putuint_with_prec(num, str_len);
	if (flags->width - str_len > 0)
		ft_putchars(' ', flags->width - str_len);
	if (flags->flag[0] == 0)
		ft_putuint_with_prec(num, str_len);
	*printed += ft_max(str_len, flags->width);
}
