/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:17:17 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 10:19:28 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

unsigned long	timestamp(void)
{
	t_timeval		tv;
	t_timezone		tz;
	unsigned long	ts;

	if (gettimeofday(&tv, &tz))
	{
		return (0);
	}
	ts = tv.tv_usec / 1000;
	ts += tv.tv_sec * 1000;
	return (ts);
}

void	set_action(t_philo *philo, t_action action)
{
	char	*action_str;

	pthread_mutex_lock(&philo->args->mutex_print);
	action_str = NULL;
	if (action == EAT)
		action_str = "is eating";
	else if (action == SLEEP)
		action_str = "is sleeping";
	else if (action == THINK)
		action_str = "is thinking";
	else if (action == TAKE_FORK)
		action_str = "has taken a fork";
	else if (action == DEAD_ALONE)
		action_str = "died";
	printf("%ld %d %s\n", timestamp(), philo->id, action_str);
	philo->action = action;
	pthread_mutex_unlock(&philo->args->mutex_print);
}
