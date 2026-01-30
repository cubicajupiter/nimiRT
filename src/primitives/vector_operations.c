/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:33:14 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 18:07:58 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "defines.h"

int	magnitude_get(float *magnitude, const tuple vector)
{
	if (!magnitude || !vector)
		return (ERROR);
	*magnitude = sqrtf(vector[X] * vector[X] + vector[Y] * vector[Y] + vector[Z]
			* vector[Z]);
	return (SUCCESS);
}

int	vector_normalise(tuple dst, tuple vector)
{
	float	magnitude;

	if (!dst || !vector)
		return (ERROR);
	magnitude_get(&magnitude, vector);
	dst[X] = vector[X] / magnitude;
	dst[Y] = vector[Y] / magnitude;
	dst[Z] = vector[Z] / magnitude;
	dst[W] = vector[W] / magnitude;
	return (SUCCESS);
}

/*
Dot product calculates the angle between two vectors (e.g. as a ray bounces off the surface of an object).
It is actually the cosine of the angle between two unit vectors.
*/
int	vector_dot(float *dot, tuple a, tuple b)
{
	if (!*dot || !a || !b)
		return (ERROR);
	*dot = a[X] * b[X] + a[Y] * b[Y] + a[Z] * b[Z] + a[W] * b[W];
	return (SUCCESS);
}

int	vector_cross(tuple dst, tuple a, tuple b)
{
	if (!dst || !a || !b)
		return (ERROR);
	dst[X] = a[Y] * b[Z] - a[Z] * b[Y];
	dst[Y] = a[Z] * b[X] - a[X] * b[Z];
	dst[Z] = a[X] * b[Y] - a[Y] * b[X];
	return (SUCCESS);
}
