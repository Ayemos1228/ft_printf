/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomeya <tsomeya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:08:15 by tsomeya           #+#    #+#             */
/*   Updated: 2021/04/18 23:54:19 by tsomeya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*ptr;

	tmp = *lst;
	ptr = NULL;
	if (!del)
		return ;
	while (tmp != NULL)
	{
		(*del)(tmp->content);
		ptr = tmp->next;
		free(tmp);
		tmp = ptr;
	}
	*lst = NULL;
}
