/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:39:38 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/09 19:20:22 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	dst_i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (*dst != '\0')
		dst++;
	while (*src != '\0' && dst_i < dstsize - dst_len - 1)
	{
		*dst = *src;
		dst++;
		src++;
		dst_i++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
