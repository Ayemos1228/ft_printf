/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:19:34 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/09 19:21:41 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_cpy;
	const unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (const unsigned char *)src;
	while (n--)
	{
		if (*src_cpy == (unsigned char)c)
		{
			*(dst_cpy)++ = *src_cpy;
			return ((void *)dst_cpy);
		}
		*(dst_cpy)++ = *(src_cpy)++;
	}
	return (NULL);
}
