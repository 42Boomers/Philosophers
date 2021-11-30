/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:17:22 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 19:11:30 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	add_philo(t_args *args, int id)
{
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	philo->id = id;
	philo->args = args;
	philo->times_eat = 0;
	philo->last_msec = 0;
	philo->action = ALIVE;
	ft_lstadd_back(&(args->members), ft_lstnew(philo));
	create_thread(philo);
	return (0);
}

int	init_philo(t_args *args)
{
	int				i;

	i = 0;
	args->start_time = timestamp();
	while (args->nb > i)
	{
		add_philo(args, ++i);
	}
	return (0);
}
