/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:53:05 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 17:11:33 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	if (lst && f)
	{
		while (lst)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
	}
}
