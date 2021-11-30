/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:17:17 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 14:22:53 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

unsigned long	timestamp(void)
{
	t_timeval		tv;
	t_timezone		tz;
	unsigned long	ts;

	gettimeofday(&tv, &tz);
	ts = tv.tv_usec / 1000;
	ts += tv.tv_sec * 1000;
	return (ts);
}

void	set_action_ts_str(t_philo *philo, t_action action, unsigned long ts,
			char *action_str)
{
	pthread_mutex_lock(&philo->args->mutex_print);
	printf("%ld %d %s\n", ts, philo->id, action_str);
	pthread_mutex_unlock(&philo->args->mutex_print);
	philo->action = action;
}
