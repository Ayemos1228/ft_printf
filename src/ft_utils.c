/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:54:39 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/28 12:27:03 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_set_fill_char(t_flags *flags)
{
	if (flags->flag[1] && !flags->flag[0])
		return ('0');
	else
		return (' ');
}

char	ft_set_fill_char_int(t_flags *flags, int digits)
{
	if (flags->flag[1] && !flags->flag[0])
		return ('0');
	(void)digits;
	if (flags->flag[0] == 1 || flags->prec != -1)
		return (' ');
	else if (flags->flag[1] == 1)
		return ('0');
	else
		return (' ');
}

int	ft_count_digit(long long n, int base)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		cnt++;
	}
	return (cnt);
}

void	ft_puthex_with_prec(unsigned int num, int is_lower, int str_len)
{
	int		div;
	int		digits;
	char	*base;

	digits = ft_count_digit(num, 16);
	div = ft_pow(16, digits - 1);
	if (str_len - digits > 0)
		ft_putchars('0', str_len - digits);
	if (is_lower)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	while (div > 0)
	{
		ft_putchar(base[num / div]);
		num %= div;
		div /= 16;
	}
}

void	ft_putchars(char c, int num)
{
	while (num > 0)
	{
		ft_putchar_fd(c, 1);
		num--;
	}
}
