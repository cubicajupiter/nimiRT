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
	tuple[X] = x;
	tuple[Y] = y;
	tuple[Z] = z;
	tuple[W] = POINT;
	return (0);
}

int	vector(tuple tuple, float x, float y, float z)
{
	tuple[X] = x;
	tuple[Y] = y;
	tuple[Z] = z;
	tuple[W] = VECTOR;
	return (0);
}

bool	is_tuple_equal(tuple a, tuple b)
{
	if (is_float_equal(a[X], b[X]) && is_float_equal(a[Y], b[Y])
		&& is_float_equal(a[Z], b[Z]))
		return (true);
	return (false);
}

int	negate_tuple(tuple new, tuple a)
{
	new[X] = 0.0 - a[X];
	new[Y] = 0.0 - a[Y];
	new[Z] = 0.0 - a[Z];
	new[W] = 0.0 - a[W];
	return (0);
}
