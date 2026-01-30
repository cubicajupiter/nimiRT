/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:19:27 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/04 18:36:27 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

long long	ft_super_atoi(const char *nptr)
{
	long long	res;
	int			sign;
	int			digit;

	res = 0;
	sign = 1;
	while (ft_isspace((int)*nptr))
		nptr++;
	if (ft_issign((int)*nptr))
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit((int)*nptr))
	{
		digit = (long)(*nptr - '0');
		res = res * 10 + (long)digit;
		if (res > INT_MAX + (long)1)
			return (res);
		nptr++;
	}
	return (res * sign);
}

bool	ft_atoi(const char *nptr, int *nbr)
{
	int	res;

	if (!ft_nan(nptr))
		return (false);
	res = ft_super_atoi(nptr);
	if (res > INT_MAX || res < INT_MIN)
		return (false);
	else
	{
		*nbr = res;
		return (true);
	}
}
