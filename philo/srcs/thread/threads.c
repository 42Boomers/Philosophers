/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:17:13 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 13:18:58 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	join_thread(void *v)
{
	t_philo	*philo;
	void	*ret;

	philo = (t_philo *)v;
	if (pthread_join(philo->thread, &ret) != 0)
	{
		printf("Error : Unable to join thread for Philo %d.\n", philo->id);
		return ;
	}
}

void	join_threads(t_args *args)
{
	ft_lstiter(args->members, join_thread);
}

int	create_thread(t_philo *philo)
{
	pthread_attr_t	*params;
	void			*arg;

	params = NULL;
	arg = philo;
	if (pthread_create(&(philo->thread), params, start, arg) != 0)
	{
		printf("Error : Unable to create thread for Philo %d.\n", philo->id);
		return (1);
	}
	return (0);
}

void	deteach_all(t_args *args, t_philo *exept)
{
	t_list	*iter;
	t_philo	*philo;

	iter = args->members;
	while (iter)
	{
		philo = (t_philo *) iter->content;
		if (exept->id != philo->id)
			pthread_detach(philo->thread);
		iter = iter->next;
	}
}
