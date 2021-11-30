/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:16:31 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 10:16:32 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	loop2(t_philo *philo, unsigned long *msec)
{
	philo->last_msec = *msec;
	philo->times_eat++;
	if (philo->args->must_eat != -1
		&& philo->times_eat >= philo->args->must_eat)
	{
		philo->action = END;
		return (1);
	}
	set_action(philo, SLEEP);
	usleep(philo->args->time_sleep * 1000);
	*msec = timestamp();
	set_action(philo, THINK);
	return (0);
}

static int	loop(t_philo *philo, unsigned long *msec)
{
	int	waiting;

	waiting = 1;
	while (waiting)
	{
		waiting = get_forks(philo);
		*msec = timestamp();
		if (*msec - philo->last_msec >= (unsigned long) philo->args->time_die)
		{
			set_action(philo, DEAD_ALONE);
			return (1);
		}
	}
	set_action(philo, EAT);
	usleep(philo->args->time_eat * 1000);
	release_forks(philo);
	return (loop2(philo, msec));
}

void	*start(void *arg)
{
	t_philo			*philo;
	unsigned long	msec;
	int				ret;

	philo = (t_philo *) arg;
	msec = timestamp();
	if (msec == 0)
	{
		printf("Error: unable to get timestamp.\n");
		return (NULL);
	}
	if (philo->args->nb == 1)
	{
		set_action(philo, DEAD_ALONE);
		return (0);
	}
	philo->last_msec = msec;
	ret = loop(philo, &msec);
	while (!ret)
		ret = loop(philo, &msec);
	return (0);
}
