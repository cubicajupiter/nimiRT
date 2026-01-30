/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:41:06 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/06 13:36:54 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_big_atof(const char *nptr, float *nbr)
{
	double	res;
	int		digit;

	res = 0.0;
	if (!ft_naf(nptr))
		return (KO);
	while (ft_isspace((int)*nptr))
		nptr++;
	if (ft_issign((int)*nptr))
		nptr++;
	while (ft_isdigit((int)*nptr))
	{
		digit = *nptr - '0';
		res = res * 10 + (double)digit;
		if (res > FLT_MAX)
			return (KO);
		nptr++;
	}
	*nbr = (float)res;
	return (OK);
}

bool	ft_atof(const char *nptr, float	*nbr)
{
	t_float	fl;
	int		i;
	int		sign;

	if (!ft_big_atof(nptr, &fl.whole))
		return (false);
	fl.dec = 0.0f;
	i = 0;
	sign = 1;
	while (ft_isspace((int)*nptr))
		nptr++;
	if (ft_issign(*nptr))
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (ft_isdigit((int)*nptr))
		nptr++;
	if (*nptr == '.' && ft_isdigit((int)*(nptr + 1)))
		nptr++;
	while (ft_isdigit((int)nptr[i]))
		fl.dec = (fl.dec * 10) + (nptr[i++] - '0');
	*nbr = ((float)fl.whole + (fl.dec / (float)ft_power(10, i))) * (float)sign;
	return (true);
}
