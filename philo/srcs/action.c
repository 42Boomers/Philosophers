/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:16:31 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 17:36:12 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	loop2(t_philo *philo)
{
	philo->times_eat++;
	if (philo->args->must_eat != -1
		&& philo->times_eat >= philo->args->must_eat)
	{
		philo->action = END;
		return (1);
	}
	set_action_s(philo);
	ft_sleep(philo->args->time_sleep * 1000);
	set_action_t(philo);
	return (0);
}

static int	loop(t_philo *philo)
{
	long	msec;

	get_forks(philo);
	msec = timestamp();
	if (msec - philo->last_msec >= (long) philo->args->time_die)
	{
		set_action_d(philo);
		return (1);
	}
	set_action_e(philo);
	philo->last_msec = msec;
	ft_sleep(philo->args->time_eat * 1000);
	release_forks(philo);
	return (loop2(philo));
}

void	*start(void *arg)
{
	t_philo			*philo;
	int				ret;

	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		ft_sleep(philo->args->time_eat * 1000);
	if (philo->args->nb == 1)
	{
		set_action_d(philo);
		return (NULL);
	}
	philo->last_msec = timestamp();
	/*if (philo->last_msec == 0)
	{
		printf("Error: unable to get timestamp.\n");
		return (NULL);
	}*/
	//pthread_mutex_unlock(&philo->args->mutex_start);
	//printf("START %d %ld\n", philo->id, philo->last_msec);
	ret = loop(philo);
	while (!ret)
		ret = loop(philo);
	return (NULL);
}
