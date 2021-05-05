/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:39:02 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/14 00:39:04 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	unsigned char	*ptr;
	unsigned char	c_in;

	i = 0;
	ptr = (unsigned char *)s;
	len = ft_strlen((const char *)ptr);
	c_in = (unsigned char)c;
	while (i <= len)
	{
		if (*ptr == c_in)
			return ((void *)ptr);
		i++;
		ptr++;
	}
	return (NULL);
}
