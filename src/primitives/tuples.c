/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:15:13 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 14:33:55 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	point(tuple tuple, float x, float y, float z)
{
	if (!tuple || !x || !y || !z)
		return (ERROR);
	tuple[X] = x;
	tuple[Y] = y;
	tuple[Z] = z;
	tuple[W] = POINT;
	return (SUCCESS);
}

int	vector(tuple tuple, float x, float y, float z)
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

int	negate_tuple(tuple new, tuple a)
{
	if (!new || !a)
		return (ERROR);
	new[X] = 0.0 - a[X];
	new[Y] = 0.0 - a[Y];
	new[Z] = 0.0 - a[Z];
	new[W] = 0.0 - a[W];
	return (SUCCESS);
}
