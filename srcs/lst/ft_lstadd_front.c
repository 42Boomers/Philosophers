/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:52:53 by tglory            #+#    #+#             */
/*   Updated: 2021/11/23 01:03:16 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (new != 0 && alst != 0)
	{
		new->next = *alst;
		*alst = new;
	}
}
