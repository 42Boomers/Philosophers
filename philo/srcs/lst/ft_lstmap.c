/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:27:55 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 17:11:33 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (del) (void *))
{
	t_list	*newlist;
	t_list	*first;

	if (f != NULL && lst != NULL && del != NULL)
	{
		first = NULL;
		while (lst != NULL)
		{
			newlist = ft_lstnew((*f)(lst->content));
			if (newlist == NULL)
			{
				ft_lstclear(&first, del);
				return (NULL);
			}
			ft_lstadd_back(&first, newlist);
			lst = lst->next;
		}
		return (first);
	}
	return (NULL);
}
