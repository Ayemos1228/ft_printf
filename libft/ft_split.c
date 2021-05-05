/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 15:18:21 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/19 23:25:23 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libc.h"

static int	free_tab(char **tab, int idx)
{
	while (idx)
		free(tab[--idx]);
	return (-1);
}

static int	arr_count(const char *str, char c)
{
	int			i;
	int			num_arr;

	i = 0;
	num_arr = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			num_arr++;
		i++;
	}
	return (num_arr);
}

static void	my_strcpy(char *dest, const char *src, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	str_to_tab(char **tab, const char *str, char c)
{
	int			i;
	int			arr_len;
	int			arr_num;

	i = 0;
	arr_len = 0;
	arr_num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			arr_len = 0;
			while (str[i + arr_len] != c && str[i + arr_len] != '\0')
				arr_len++;
			tab[arr_num] = (char *)malloc(sizeof(char) * (arr_len + 1));
			if (tab[arr_num] == NULL)
				return (free_tab(tab, arr_num));
			my_strcpy(tab[arr_num], &str[i], arr_len);
			arr_num++;
			i += arr_len;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int			arr_num;
	char		**ans;

	if (!s)
		return (NULL);
	arr_num = arr_count(s, c);
	ans = (char **)malloc(sizeof(char *) * (arr_num + 1));
	if (ans == NULL)
		return (NULL);
	ans[arr_num] = NULL;
	if (str_to_tab(ans, s, c) == -1)
	{
		free(ans);
		return (NULL);
	}
	return (ans);
}
