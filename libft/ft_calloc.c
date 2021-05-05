/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 23:20:44 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/13 22:37:10 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	alloc_size;
	void	*mem;

	alloc_size = count * size;
	if (count == 0 || size == 0)
	{
		mem = malloc(0);
		if (mem == NULL)
			return (NULL);
		return (mem);
	}
	if (size != alloc_size / count)
		return (NULL);
	mem = malloc(alloc_size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, alloc_size);
	return (mem);
}
