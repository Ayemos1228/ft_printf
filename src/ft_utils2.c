/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:11:49 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/26 12:07:20 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_str(const char *begin, const char **fmt, int *printed)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, begin, *fmt - begin);
	*printed += *fmt - begin;
}

void	ft_init_flags(t_flags *flags)
{
	flags->flag[0] = 0;
	flags->flag[1] = 0;
	flags->prec = -1;
	flags->width = -1;
}

int	ft_flagtoi(char c)
{
	if (c == '-')
		return (0);
	else
		return (1);
}

void	ft_putnbr_base(unsigned long long nb, char *base)
{
	char				c;
	unsigned long long	base_size;

	base_size = ft_strlen(base);
	if (nb < base_size)
	{
		c = base[nb];
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr_base(nb / base_size, base);
		c = base[nb % base_size];
		write(1, &c, 1);
	}
}
