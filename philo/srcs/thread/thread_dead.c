/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_dead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:17:09 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 20:10:57 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_dead(t_args *args)
{
	t_list	*iter;
	t_philo	*philo;
	long	msec;

	iter = args->members;
	while (iter)
	{
		philo = (t_philo *)iter->content;
		msec = timestamp();
		if (philo->last_msec != 0
			&& msec - philo->last_msec >= (long) philo->args->time_die)
		{
			set_action_d(philo);
			return (-2);
		}
		if (philo->action == DEAD_ALONE)
			return (-2);
		if (philo->action == END)
			return (-1);
		iter = iter->next;
	}
	return (0);
}

int	w8_for(t_args *args)
{
	int	ret;

	ret = check_dead(args);
	while (!ret)
	{
		ft_sleep(1000);
		ret = check_dead(args);
	}
	return (ret);
}
