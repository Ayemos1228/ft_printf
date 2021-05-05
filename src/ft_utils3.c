/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:32:45 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/26 14:34:46 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_zero(int *printed, t_flags *flags)
{
	if (flags->prec == -1)
	{
		if (flags->flag[1] == 0 && flags->width > 0)
			ft_putchars(' ', flags->width - 1);
		if (flags->flag[1] == 1 && flags->width > 0)
			ft_putchars('0', flags->width - 1);
		ft_putchar('0');
	}
	if (flags->prec == 0)
	{
		if (flags->width > 0)
			ft_putchars(' ', flags->width);
	}
	if (flags->prec > 0)
	{
		if (flags->width > flags->prec)
			ft_putchars(' ', flags->width - flags->prec);
		ft_putchars('0', flags->prec);
	}
	if (flags->prec > 0 || flags->width > 0)
		*printed += ft_max(flags->prec, flags->width);
	else if (flags->prec != 0)
		*printed += 1;
}

void	ft_print_zero_minus(int *printed, t_flags *flags)
{
	if (flags->prec == -1)
	{
		if (flags->flag[1] == 1 && flags->width > 0)
			ft_putchars('0', flags->width - 1);
		ft_putchar('0');
		if (flags->flag[1] == 0 && flags->width > 0)
			ft_putchars(' ', flags->width - 1);
	}
	if (flags->prec == 0)
	{
		if (flags->width > 0)
			ft_putchars(' ', flags->width);
	}
	if (flags->prec > 0)
	{
		ft_putchars('0', flags->prec);
		if (flags->width > flags->prec)
			ft_putchars(' ', flags->width - flags->prec);
	}
	if (flags->prec > 0 || flags->width > 0)
		*printed += ft_max(flags->prec, flags->width);
	else if (flags->prec != 0)
		*printed += 1;
}

int	ft_get_hex_len(unsigned int num, t_flags *flags)
{
	int	ret;

	if (flags->prec == -1)
	{
		if (flags->flag[1] == 0)
			ret = ft_count_digit(num, 16);
		else
			ret = ft_max(flags->width, ft_count_digit(num, 16));
	}
	else if (flags->prec == 0)
		ret = ft_count_digit(num, 16);
	else
	{
		if (num > 0)
			ret = ft_max(ft_count_digit(num, 16), flags->prec);
		else
			ret = ft_max(flags->prec + 1, ft_count_digit(num, 16));
	}
	return (ret);
}
