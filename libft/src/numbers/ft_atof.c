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
#include <asm-generic/errno.h>

int	ft_big_atof(const char *nptr, float *nbr)
{
	double	res;
	int		digit;

	res = 0.0;
	if (!ft_naf(nptr))
		return (ft_liberror(EINVAL, "ft_big_atof"));
	while (ft_isspace((int)*nptr))
		nptr++;
	if (ft_issign((int)*nptr))
		nptr++;
	while (ft_isdigit((int)*nptr))
	{
		digit = *nptr - '0';
		res = res * 10 + (double)digit;
		if (res > FLT_MAX)
			return (FAIL);
		nptr++;
	}
	*nbr = (float)res;
	return (SUCCESS);
}

static int	find_decimal_and_handle_sign(const char **nptr, int *sign)
{
	const char	*s;
	int			tmp;

	if (!nptr || !sign)
		return (ft_liberror(EINHERIT, "find_decimal_and_handle_sign"));
	s = *nptr;
	tmp = 1;
	while (ft_isspace((int)*s))
		s++;
	if (ft_issign(*s))
	{
		if (*s == '-')
			tmp *= -1;
		s++;
	}
	while (ft_isdigit((int)*s))
		s++;
	if (*s == '.' && ft_isdigit((int)*(s + 1)))
		s++;
	*nptr = s;
	*sign = tmp;
	return (SUCCESS);
}

int	ft_atof(const char *nptr, float	*nbr)
{
	t_float	fl;
	int		i;
	int		sign;
	int		flag;

	flag = ft_big_atof(nptr, &fl.whole);
	if (flag == ERROR)
		return (ft_liberror(EINHERIT, "ft_atof"));
	if (flag == FAIL)
		return (FAIL);
	fl.dec = 0.0f;
	find_decimal_and_handle_sign(&nptr, &sign);
	i = 0;
	while (ft_isdigit((int)nptr[i]))
		fl.dec = (fl.dec * 10) + (nptr[i++] - '0');
	*nbr = ((float)fl.whole + (fl.dec / (float)ft_power(10, i))) * (float)sign;
	return (SUCCESS);
}
