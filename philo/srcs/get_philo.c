/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:16:56 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 10:16:57 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	get_forks(t_philo *philo)
{
	t_args	*args;
	int		target_id;

	args = philo->args;
	target_id = philo->id % args->nb;
	pthread_mutex_lock(&args->mutexs[philo->id - 1]);
	pthread_mutex_lock(&args->mutexs[target_id]);
	if (args->forks[target_id] == TAKEN || args->forks[philo->id - 1] == TAKEN)
		return (1);
	set_action(philo, TAKE_FORK);
	args->forks[philo->id - 1] = TAKEN;
	args->forks[target_id] = TAKEN;
	return (0);
}

void	release_forks(t_philo *philo)
{
	t_args	*args;
	int		target_id;

	args = philo->args;
	target_id = philo->id % args->nb;
	if (args->forks[target_id] == FREE || args->forks[philo->id - 1] == FREE)
		return ;
	args->forks[philo->id - 1] = FREE;
	args->forks[target_id] = FREE;
	pthread_mutex_unlock(&args->mutexs[philo->id - 1]);
	pthread_mutex_unlock(&args->mutexs[target_id]);
}
