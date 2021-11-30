/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:17:17 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 19:44:10 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	timestamp(void)
{
	t_timeval		tv;
	t_timezone		tz;
	long			ts;

	gettimeofday(&tv, &tz);
	ts = tv.tv_usec / 1000;
	ts += tv.tv_sec * 1000;
	return (ts);
}

void	set_action_ts_str(t_philo *philo, t_action action, long ts,
			char *action_str)
{
	pthread_mutex_lock(&philo->args->mutex_print);
	printf("%ld %d %s\n", ts - philo->args->start_time, philo->id, action_str);
	if (action != DEAD_ALONE)
		pthread_mutex_unlock(&philo->args->mutex_print);
	philo->action = action;
}

void	ft_sleep(int time_micro)
{
	long	ts;
	long	want_ts;

	ts = timestamp();
	want_ts = ts + (time_micro / 1000);
	while (want_ts > ts)
	{
		usleep(200);
		ts = timestamp();
	}
}
