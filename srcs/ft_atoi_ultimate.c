/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ultimate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:07:40 by tglory            #+#    #+#             */
/*   Updated: 2021/11/17 19:16:49 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	*ft_atoi_ultimate2(const char *str, unsigned int nb,
	int neg, int *ret)
{
	int		swap;
	int		i;

	i = 0;
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		if (i++ > 10 || (neg == -1 && nb > 2147483648)
			|| (neg == 1 && nb > 2147483647))
			return (0);
		str++;
	}
	while ((*str == '\t') || (*str == '\v') || (*str == '\n')
		|| (*str == '\r') || (*str == '\f') || (*str == ' '))
		str++;
	if (*str != 0)
		return (0);
	swap = ((int)nb * neg);
	ret = &swap;
	return (ret);
}

/** Atoi without allowing letter, and check INT range. It return a pointer
 * @return int* or NULL
 * @param str should be in int range
 */
int	*ft_atoi_ultimate(const char *str)
{
	unsigned int	nb;
	int				neg;
	int				*ret;

	nb = 0;
	neg = 1;
	ret = 0;
	while ((*str == '\t') || (*str == '\v') || (*str == '\n')
		|| (*str == '\r') || (*str == '\f') || (*str == ' '))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (ft_atoi_ultimate2(str, nb, neg, ret));
}
