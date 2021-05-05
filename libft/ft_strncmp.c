/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:18:01 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/09 19:20:34 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1_cpy;
	const unsigned char	*s2_cpy;

	i = 0;
	s1_cpy = (const unsigned char *)s1;
	s2_cpy = (const unsigned char *)s2;
	while (i < n && (s1_cpy[i] != '\0' || s2_cpy[i] != '\0'))
	{
		if (s1_cpy[i] != s2_cpy[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return (s1_cpy[i] - s2_cpy[i]);
}
