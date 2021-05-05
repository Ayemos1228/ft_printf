/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:49:58 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/14 00:57:54 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	c_in;

	c_in = c;
	ptr = (unsigned char *)s;
	i = ft_strlen((const char *)ptr);
	while (1)
	{
		if (ptr[i] == c_in)
			return ((void *)&ptr[i]);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
