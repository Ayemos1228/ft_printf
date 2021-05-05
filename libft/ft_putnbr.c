/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 09:40:44 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/24 19:17:19 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int	sign;

	sign = 1;
	if (nb < 0)
	{
		sign = -1;
		ft_putchar('-');
	}
	if (nb < 10 && nb > -10)
		ft_putchar('0' + nb * sign);
	else
	{
		ft_putnbr(nb / 10 * sign);
		ft_putchar(nb % 10 * sign + '0');
	}
}
