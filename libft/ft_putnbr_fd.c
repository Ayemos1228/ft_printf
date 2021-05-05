/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 18:12:22 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/09 19:18:27 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int		sign;
	char	c;

	sign = 1;
	if (nb < 0)
	{
		sign = -1;
		write(fd, "-", 1);
	}
	if (nb < 10 && nb > -10)
	{
		c = '0' + nb * sign;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(nb / 10 * sign, fd);
		c = '0' + nb % 10 * sign;
		write(fd, &c, 1);
	}
}
