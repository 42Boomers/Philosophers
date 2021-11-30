/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:17:00 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 14:15:03 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_args	*arg;

	arg = args(ac, av);
	if (!arg)
		return (1);
	pthread_mutex_init(&arg->mutex_print, NULL);
	pthread_mutex_init(&arg->mutex_start, NULL);
	init_philo(arg);
	if (w8_for(arg) != -2)
		join_threads(arg);
	else
		pthread_mutex_lock(&arg->mutex_print);
	unlock_all_mutex(arg);
	destroy_all_mutex(arg);
	ft_lstclear(&(arg->members), free);
	free(arg->forks);
	free(arg->mutexs);
	pthread_mutex_unlock(&arg->mutex_start);
	pthread_mutex_destroy(&arg->mutex_start);
	free(arg);
	return (0);
}
