/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:12:40 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/26 12:37:34 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_field_width(const char **fmt, va_list ap, t_flags *flags)
{
	int	width;

	width = 0;
	if (**fmt != '*' && !ft_isdigit(**fmt))
		return ;
	if (**fmt == '*')
	{
		flags->width = va_arg(ap, int);
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->flag[0] = 1;
			flags->flag[1] = 0;
		}
		(*fmt)++;
		return ;
	}
	while (ft_isdigit(**fmt))
	{
		width *= 10;
		width += **fmt - '0';
		(*fmt)++;
	}
	flags->width = width;
}

void	ft_get_prec(const char **fmt, va_list ap, t_flags *flags)
{
	if (**fmt != '.')
		return ;
	(*fmt)++;
	flags->prec = 0;
	if (**fmt == '*')
	{
		flags->prec = va_arg(ap, int);
		if (flags->prec < 0)
			flags->prec = -1;
		(*fmt)++;
		return ;
	}
	else if (**fmt == '-')
	{
		flags->prec = -1;
		(*fmt)++;
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
	while (ft_isdigit(**fmt))
	{
		flags->prec *= 10;
		flags->prec += **fmt - '0';
		(*fmt)++;
	}
}

void	print_fmt(const char **fmt, va_list ap, int *printed, t_flags *flags)
{
	if (**fmt == '%')
		ft_print_perc(fmt, printed, flags);
	else if (**fmt == 'i' || **fmt == 'd')
		ft_print_int(fmt, ap, printed, flags);
	else if (**fmt == 'p')
		ft_print_ptr(fmt, ap, printed, flags);
	else if (**fmt == 'c')
		ft_print_char(fmt, ap, printed, flags);
	else if (**fmt == 's')
		ft_print_str(fmt, ap, printed, flags);
	else if (**fmt == 'u')
		ft_print_uint(fmt, ap, printed, flags);
	else if (**fmt == 'x')
		ft_print_lowhex(fmt, ap, printed, flags);
	else if (**fmt == 'X')
		ft_print_uphex(fmt, ap, printed, flags);
	else
		*printed = -1;
}

void	ft_process_fmt(const char *begin, const char **fmt, \
int *printed, va_list ap)
{
	t_flags	flags;

	ft_init_flags(&flags);
	(*fmt)++;
	while (**fmt == '-' || **fmt == '0')
	{
		flags.flag[ft_flagtoi(**fmt)] = 1;
		(*fmt)++;
	}
	if (*fmt - begin > 3)
	{
		*printed = -1;
		return ;
	}
	if (flags.flag[0] == 1)
		flags.flag[1] = 0;
	ft_get_field_width(fmt, ap, &flags);
	ft_get_prec(fmt, ap, &flags);
	print_fmt(fmt, ap, printed, &flags);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			printed;
	const char	*begin;

	printed = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		printed = -1;
	while (printed >= 0 && *fmt)
	{
		begin = fmt;
		if (*begin != '%')
			ft_write_str(begin, &fmt, &printed);
		else
			ft_process_fmt(begin, &fmt, &printed, ap);
	}
	va_end(ap);
	return (printed);
}
