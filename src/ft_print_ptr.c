/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:09:27 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/26 14:34:20 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr_with_prec(unsigned long long ptr, t_flags *flags)
{
	int	idx;

	idx = 0;
	write(1, "0x", 2);
	if (ptr != 0)
	{
		while (idx++ < flags->prec - 9)
			write(1, "0", 1);
		ft_putnbr_base(ptr, "0123456789abcdef");
	}
	else
	{
		while (idx++ < flags->prec - 1)
			write(1, "0", 1);
		if (flags->prec != 0)
			write(1, "0", 1);
	}
}

static int	ft_get_ptr_len(unsigned long long ptr, t_flags *flags)
{
	int	ret;

	if (flags->prec == -1)
	{
		if (flags->flag[1] == 0)
			ret = ft_count_digit(ptr, 16);
		else
			ret = ft_max(flags->width, ft_count_digit(ptr, 16));
	}
	else if (flags->prec == 0)
		ret = ft_count_digit(ptr, 16);
	else
	{
		if (ptr > 0)
			ret = ft_max(ft_count_digit(ptr, 16), flags->prec);
		else
			ret = ft_max(flags->prec + 1, ft_count_digit(ptr, 16));
	}
	return (ret);
}

static void	ft_print_ptr_minus(va_list ap, int *printed, t_flags *flags)
{
	unsigned long long	ptr;
	int					str_len;
	int					idx;

	ptr = (unsigned long long)va_arg(ap, void *);
	str_len = ft_get_ptr_len(ptr, flags) + 2;
	if (!ptr)
	{
		ptr = 0;
		str_len = ft_max(flags->prec + 2, 3);
		if (flags->prec == 0)
			str_len = 2;
	}
	idx = 0;
	ft_putptr_with_prec(ptr, flags);
	while (idx < flags->width - str_len)
	{
		write(1, " ", 1);
		idx++;
	}
	*printed += ft_max(str_len, flags->width);
}

void	ft_print_ptr(const char **fmt, va_list ap, int *printed, t_flags *flags)
{
	unsigned long long	ptr;
	int					str_len;

	(*fmt)++;
	if (flags->flag[0])
	{
		ft_print_ptr_minus(ap, printed, flags);
		return ;
	}
	ptr = (unsigned long long)va_arg(ap, void *);
	str_len = ft_get_ptr_len(ptr, flags) + 2;
	if (!ptr)
	{
		ptr = 0;
		str_len = ft_max(flags->prec + 2, 3);
		if (flags->prec == 0)
			str_len = 2;
	}
	ft_putchars(' ', flags->width - str_len);
	ft_putptr_with_prec(ptr, flags);
	*printed += ft_max(str_len, flags->width);
}
