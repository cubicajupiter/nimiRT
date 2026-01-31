/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_arithmetics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:27:35 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 17:11:36 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	tuple_add(tuple dst, tuple const a, const tuple b)
{
	if (!dst || !a || !b)
		return (ERROR);
	dst[X] = a[X] + b[X];
	dst[Y] = a[Y] + b[Y];
	dst[Z] = a[Z] + b[Z];
	dst[W] = a[W] + b[W];
	return (SUCCESS);
}

int	tuple_subtract(tuple dst, tuple a, const tuple b)
{
	if (!dst || !a || !b)
		return (ERROR);
	dst[X] = a[X] - b[X];
	dst[Y] = a[Y] - b[Y];
	dst[Z] = a[Z] - b[Z];
	dst[W] = a[W] - b[W];
	return (SUCCESS);
}

int	vector_multiply(tuple dst, const float scalar, tuple vector)
{
	if (!dst || !scalar || !vector)
		return (ERROR);
	dst[X] = vector[X] * scalar;
	dst[Y] = vector[Y] * scalar;
	dst[Z] = vector[Z] * scalar;
	dst[X] = vector[X] * scalar;
	return (SUCCESS);
}

int	vector_divide(tuple dst, const float scalar, tuple vector)
{
	if (!dst || !scalar || !vector)
		return (ERROR);
	dst[X] = vector[X] / scalar;
	dst[Y] = vector[Y] / scalar;
	dst[Z] = vector[Z] / scalar;
	dst[X] = vector[X] / scalar;
	return (SUCCESS);
}
