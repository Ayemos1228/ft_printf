/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:51:37 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/20 11:30:11 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	unsigned int	num;
	int				digits;

	num = n;
	if (n < 0)
		num *= -1;
	digits = 0;
	while (num > 0)
	{
		num /= 10;
		digits++;
	}
	if (n < 0 || n == 0)
		return (digits + 1);
	return (digits);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	int				digits;
	int				start;

	digits = count_digit(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (NULL);
	str[digits] = '\0';
	start = 0;
	num = n;
	if (n < 0)
	{
		num *= -1;
		str[0] = '-';
		start = 1;
	}
	while (digits > start)
	{
		str[--digits] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
