/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:16:56 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 19:21:04 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_forks(t_philo *philo)
{
	t_args	*args;
	int		target_id;

	args = philo->args;
	target_id = philo->id % args->nb;
	pthread_mutex_lock(&args->mutexs[target_id]);
	set_action_tf(philo);
	pthread_mutex_lock(&args->mutexs[philo->id - 1]);
	set_action_tf(philo);
	return (0);
}

void	release_forks(t_philo *philo)
{
	t_args	*args;
	int		target_id;

	args = philo->args;
	target_id = philo->id % args->nb;
	pthread_mutex_unlock(&args->mutexs[philo->id - 1]);
	pthread_mutex_unlock(&args->mutexs[target_id]);
}
