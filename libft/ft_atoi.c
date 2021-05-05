/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:21:24 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/14 00:50:00 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			idx;
	__int128_t	ans;
	int			sign;

	idx = 0;
	ans = 0;
	sign = 1;
	while (ft_isspace(nptr[idx]))
		idx++;
	if (nptr[idx] == '-' || nptr[idx] == '+')
	{
		if (nptr[idx++] == '-')
			sign = -1;
	}
	while ('0' <= nptr[idx] && nptr[idx] <= '9')
	{
		ans = ans * 10 + nptr[idx++] - '0';
		if (ans > __LONG_MAX__ && sign == 1)
			return ((int)__LONG_MAX__);
		if (ans - 1 > __LONG_MAX__ && sign == -1)
			return ((int)(-__LONG_MAX__ - 1));
	}
	return ((int)ans * sign);
}
