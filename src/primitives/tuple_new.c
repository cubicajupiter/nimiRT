/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:15:13 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 17:10:36 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	point_new(tuple tuple, float x, float y, float z)
{
	if (!tuple || !x || !y || !z)
		return (ERROR);
	tuple[X] = x;
	tuple[Y] = y;
	tuple[Z] = z;
	tuple[W] = POINT;
	return (SUCCESS);
}

int	vector_new(tuple tuple, float x, float y, float z)
{
	if (!tuple || !x || !y || !z)
		return (ERROR);
	tuple[X] = x;
	tuple[Y] = y;
	tuple[Z] = z;
	tuple[W] = VECTOR;
	return (SUCCESS);
}

int	is_tuple_equal(tuple a, tuple b)
{
	if (!a || !b)
		return (ERROR);
	if (is_float_equal(a[X], b[X]) && is_float_equal(a[Y], b[Y])
		&& is_float_equal(a[Z], b[Z]))
		return (TRUE);
	return (FALSE);
}

int	vector_negate(tuple dst, tuple src)
{
	if (!dst || !src)
		return (ERROR);
	dst[X] = 0.0 - src[X];
	dst[Y] = 0.0 - src[Y];
	dst[Z] = 0.0 - src[Z];
	dst[W] = 0.0 - src[W];
	return (SUCCESS);
}
