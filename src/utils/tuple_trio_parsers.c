/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atotuple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:11:02 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/12 14:14:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static const char	*next_csv_get(const char *nptr);

int	ft_atotuple(t_tuple dst, const char *nptr)
{
	const char	*ptr[3];
	t_fl		position[3];

	if (!dst || !nptr)
		return (ft_error(EINVAL, "ft_atotuple"));
	ptr[0] = nptr;
	nptr = next_csv_get(nptr);
	if (!nptr)
		return (FAIL);
	ptr[1] = nptr;
	nptr = next_csv_get(nptr);
	if (!nptr)
		return (FAIL);
	ptr[2] = nptr;
	if (ft_atof(ptr[0], &position[X]) != SUCCESS
		|| ft_atof(ptr[1], &position[Y]) != SUCCESS
		|| ft_atof(ptr[2], &position[Z]) != SUCCESS)
		return (ft_error(EINHERIT, "ft_atotuple"));
	return (point_new(dst, position[X], position[Y], position[Z]));
}

int	ft_atotrio(t_trio dst, const char *nptr)
{
	const char	*ptr[3];
	int			color[3];

	if (!dst || !nptr)
		return (ft_error(EINVAL, "ft_atotrio"));
	ptr[0] = nptr;
	nptr = next_csv_get(nptr);
	if (!nptr)
		return (FAIL);
	ptr[1] = nptr;
	nptr = next_csv_get(nptr);
	if (!nptr)
		return (FAIL);
	ptr[2] = nptr;
	if (ft_atoi(ptr[0], &color[R]) != SUCCESS
		|| ft_atoi(ptr[1], &color[G]) != SUCCESS
		|| ft_atoi(ptr[2], &color[B]) != SUCCESS)
		return (ft_error(EINHERIT, "ft_atotrio"));
	return (color_uint_to_trio(dst, color));
}

static const char	*next_csv_get(const char *nptr)
{
	while (*nptr && ft_isfloat(*nptr))
	{
		nptr++;
		if (*nptr == ',' && nptr[1])
			return (nptr + 1);
	}
	return (NULL);
}
