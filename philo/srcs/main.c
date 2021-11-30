/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:17:00 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 20:15:16 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_args	*arg;

	arg = args(ac, av);
	if (!arg)
		return (1);
	pthread_mutex_init(&arg->mutex_print, NULL);
	init_philo(arg);
	if (w8_for(arg) != -2)
		join_threads(arg);
	unlock_all_mutex(arg);
	destroy_all_mutex(arg);
	ft_lstclear(&(arg->members), free);
	free(arg->mutexs);
	free(arg);
	return (0);
}
