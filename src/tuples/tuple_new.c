/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:15:13 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/10 19:13:01 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	point_new(t_tuple tuple, t_fl x, t_fl y, t_fl z)
{
	if (!tuple)
		return (ft_error(EINVAL, "point_new"));
	tuple[X] = x;
	tuple[Y] = y;
	tuple[Z] = z;
	tuple[W] = POINT;
	return (SUCCESS);
}

int	vector_new(t_tuple tuple, t_fl x, t_fl y, t_fl z)
{
	if (!tuple)
		return (ft_error(EINVAL, "vector_new"));
	tuple[X] = x;
	tuple[Y] = y;
	tuple[Z] = z;
	tuple[W] = VECTOR;
	return (SUCCESS);
}

int	is_tuple_equal(t_tuple a, t_tuple b)
{
	if (!a || !b)
		return (ft_error(EINVAL, "is_tuple_equal"));
	if (is_float_equal(a[X], b[X]) && is_float_equal(a[Y], b[Y])
		&& is_float_equal(a[Z], b[Z]))
		return (TRUE);
	return (FALSE);
}

int	vector_negate(t_tuple dst, t_tuple src)
{
	if (!dst || !src)
		return (ft_error(EINVAL, "vector_negate"));
	dst[X] = 0.0 - src[X];
	dst[Y] = 0.0 - src[Y];
	dst[Z] = 0.0 - src[Z];
	dst[W] = 0.0 - src[W];
	return (SUCCESS);
}

int	tuple_copy(t_tuple dst, t_tuple src)
{
	if (!dst || !src)
		return (ft_error(EINVAL, "tuple_copy"));
	dst[X] = src[X];
	dst[Y] = src[Y];
	dst[Z] = src[Z];
	dst[W] = src[W];
	return (SUCCESS);
}
