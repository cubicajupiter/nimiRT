/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_converters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:52:10 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 13:54:11 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static const char	*next_csv_get(const char *nptr);
static int			ft_atotuple_helper(t_fl *dst, const char *nptr);

int	ft_atopoint(t_tuple dst, const char *nptr)
{
	t_fl	xyz[3];
	int		flag;

	flag = ft_atotuple_helper(xyz, nptr);
	if (flag == FAIL)
		return (FAIL);
	if (flag == ERROR)
		return (ft_error(EINHERIT, "ft_atopoint"));
	return (point_new(dst, xyz[X], xyz[Y], xyz[Z]));
}

int	ft_atovector(t_tuple dst, const char *nptr)
{
	t_fl	xyz[3];
	int		flag;

	flag = ft_atotuple_helper(xyz, nptr);
	if (flag == FAIL)
		return (FAIL);
	if (flag == ERROR)
		return (ft_error(EINHERIT, "ft_atovector"));
	return (vector_new(dst, xyz[X], xyz[Y], xyz[Z]));
}

static int	ft_atotuple_helper(t_fl *dst, const char *nptr)
{
	const char	*ptr[3];

	if (!dst || !nptr)
		return (ft_error(EINVAL, "ft_atotuple"));
	ptr[0] = nptr;
	nptr = next_csv_get(nptr);
	if (!nptr)
		return (rt_invalid((*ptr)[0]));
	ptr[1] = nptr;
	nptr = next_csv_get(nptr);
	if (!nptr)
		return (rt_invalid((*ptr)[1]));
	ptr[2] = nptr;
	if (ft_atof(ptr[0], &dst[X]) != SUCCESS
		|| ft_atof(ptr[1], &dst[Y]) != SUCCESS
		|| ft_atof(ptr[2], &dst[Z]) != SUCCESS)
		return (ft_error(EINHERIT, "ft_atotuple"));
	return (SUCCESS);
}

int	ft_atotrio(t_trio dst, const char *nptr)
{
	const char	*ptr[3];
	int			color[3];
	int			flag;

	if (!dst || !nptr)
		return (ft_error(EINVAL, "ft_atotrio"));
	ptr[0] = nptr;
	nptr = next_csv_get(nptr);
	if (!nptr)
		return (rt_invalid((*ptr)[0]));
	ptr[1] = nptr;
	nptr = next_csv_get(nptr);
	if (!nptr)
		return (rt_invalid((*ptr)[0]));
	ptr[2] = nptr;
	if (ft_atoi(ptr[0], &color[R]) != SUCCESS
		|| ft_atoi(ptr[1], &color[G]) != SUCCESS
		|| ft_atoi(ptr[2], &color[B]) != SUCCESS)
		return (ft_error(EINHERIT, "ft_atotrio"));
	flag = color_uint_to_trio(dst, color);
	if (flag == FAIL)
		rt_out_of_limits("color");
	return (flag);
}

static const char	*next_csv_get(const char *nptr)
{
	while (*nptr && ft_isfloat(*nptr))
	{
		nptr++;
		if (*nptr == ',' && ft_isfloat(nptr[1]))
			return (nptr + 1);
	}
	return (NULL);
}
