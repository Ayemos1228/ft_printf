/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:55:10 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/09 19:19:51 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s_cpy;

	i = 0;
	s_cpy = (const unsigned char *)s;
	while (i < n)
	{
		if (s_cpy[i] == (unsigned char)c)
			return ((void *)&s_cpy[i]);
		i++;
	}
	return (NULL);
}
