/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:16:31 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 14:17:35 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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
	usleep(philo->args->time_sleep * 1000);
	set_action_t(philo);
	return (0);
}

static int	loop(t_philo *philo)
{
	unsigned long	msec;

	msec = timestamp();
	get_forks(philo);
	if (msec - philo->last_msec > (unsigned long) philo->args->time_die)
	{
		printf("DIED %d %ld\n", philo->id, msec - philo->last_msec);
		set_action_d(philo);
		return (1);
	}
	else
		printf("NOT DIED %d %ld\n", philo->id, msec - philo->last_msec);
	set_action_e(philo);
	philo->last_msec = timestamp();
	usleep(philo->args->time_eat * 1000);
	release_forks(philo);
	return (loop2(philo));
}

void	*start(void *arg)
{
	t_philo			*philo;
	int				ret;

	philo = (t_philo *) arg;
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
