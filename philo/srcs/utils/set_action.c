/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:14:59 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 17:11:33 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_action_e(t_philo *philo)
{
	set_action_ts_str(philo, EAT, timestamp(), "is eating");
}

void	set_action_t(t_philo *philo)
{
	set_action_ts_str(philo, THINK, timestamp(), "is thinking");
}

void	set_action_s(t_philo *philo)
{
	set_action_ts_str(philo, SLEEP, timestamp(), "is sleeping");
}

void	set_action_d(t_philo *philo)
{
	set_action_ts_str(philo, DEAD_ALONE, timestamp(), "died");
}

void	set_action_tf(t_philo *philo)
{
	set_action_ts_str(philo, TAKE_FORK, timestamp(), "has taken a fork");
}
