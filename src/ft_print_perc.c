/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 19:42:17 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/24 21:46:33 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_perc_minus(int *printed, t_flags *flags)
{
	int		idx;

	idx = 0;
	write(1, "%", 1);
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

void	ft_print_perc(const char **fmt, int *printed, t_flags *flags)
{
	char	fill_char;
	int		idx;

	(*fmt)++;
	if (flags->flag[0])
	{
		ft_print_perc_minus(printed, flags);
		return ;
	}
	fill_char = ft_set_fill_char(flags);
	idx = 0;
	while (idx < flags->width - 1)
	{
		write(1, &fill_char, 1);
		idx++;
	}
	write(1, "%", 1);
	if (flags->width == -1)
		*printed += 1;
	else
		*printed += flags->width;
}
