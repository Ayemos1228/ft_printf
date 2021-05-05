/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:28:40 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/14 00:48:06 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;
	size_t	haystack_len;
	char	*copy;

	i = 0;
	j = 0;
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	copy = (char *)haystack;
	if (needle_len == 0)
		return (copy);
	while (i <= haystack_len - needle_len && i < len)
	{
		while ((j < needle_len) && (copy[i + j] == needle[j]))
			j++;
		if (i + j > len)
			return (NULL);
		if (j == needle_len)
			return (&copy[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
