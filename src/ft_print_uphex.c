/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uphex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 23:09:40 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/26 14:34:36 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_uphex(const char **fmt, va_list ap, \
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
	str_len = ft_get_hex_len(num, flags);
	if (flags->flag[0] == 1)
		ft_puthex_with_prec(num, 0, str_len);
	if (flags->width - str_len > 0)
		ft_putchars(' ', flags->width - str_len);
	if (flags->flag[0] == 0)
		ft_puthex_with_prec(num, 0, str_len);
	*printed += ft_max(str_len, flags->width);
}
