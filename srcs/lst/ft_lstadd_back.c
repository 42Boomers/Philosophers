/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:52:49 by tglory            #+#    #+#             */
/*   Updated: 2021/11/23 01:03:13 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (alst && *alst && new)
		ft_lstlast(*alst)->next = new;
	else
		ft_lstadd_front(alst, new);
}
