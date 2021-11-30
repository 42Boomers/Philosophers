/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ultimate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:07:40 by tglory            #+#    #+#             */
/*   Updated: 2021/11/30 17:11:33 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_atoi_ultimate2(const char *str)
{
	int				i;
	unsigned int	nb;

	nb = 0;
	i = 0;
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		if (i++ > 10 || nb > 2147483647)
			return (-1);
		str++;
	}
	while ((*str == '\t') || (*str == '\v') || (*str == '\n')
		|| (*str == '\r') || (*str == '\f') || (*str == ' '))
		str++;
	if (*str != 0)
		return (-1);
	return (nb);
}

int	ft_atoi_ultimate(const char *str)
{
	while ((*str == '\t') || (*str == '\v') || (*str == '\n')
		|| (*str == '\r') || (*str == '\f') || (*str == ' '))
		str++;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	return (ft_atoi_ultimate2(str));
}
