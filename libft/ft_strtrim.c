/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:37:32 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/22 00:09:53 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_trim(char const *s1, char const *set, size_t *i, size_t *lst)
{
	while (to_trim(s1[*i], set) && *i < *lst)
		*i = *i + 1;
	while (to_trim(s1[*lst], set) && *lst > 0)
		*lst = *lst - 1;
	if (*i > *lst)
		return (-1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	lst;
	char	*ret;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	lst = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0 || ft_trim(s1, set, &i, &lst) == -1)
		return (ft_strdup(""));
	ret = (char *)ft_calloc(lst - i + 2, sizeof(char));
	ft_strlcpy(ret, &s1[i], lst - i + 2);
	return (ret);
}
