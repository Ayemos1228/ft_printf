/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:30:04 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/18 23:18:12 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	if (dst_cpy < src_cpy)
	{
		i = 0;
		while (i < len)
		{
			dst_cpy[i] = src_cpy[i];
			i++;
		}
	}
	if (dst_cpy > src_cpy)
	{
		i = len;
		while (i-- != 0)
			dst_cpy[i] = src_cpy[i];
	}
	return (dst);
}
