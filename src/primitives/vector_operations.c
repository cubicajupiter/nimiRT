/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:33:14 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 17:12:02 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

int	scale_vector(tuple new, const float scalar, tuple vector)
{
	if (!new || !scalar || !vector)
		return (ERROR);
	new[X] = vector[X] * scalar;
	new[Y] = vector[Y] * scalar;
	new[Z] = vector[Z] * scalar;
	new[X] = vector[X] * scalar;
	return (SUCCESS);
}

int	get_magnitude(float *magn, const tuple vector)
{
	if (!magn || vector)
		return (ERROR);
	*magn = sqrtf(vector[X] * vector[X] + vector[Y] * vector[Y] + vector[Z]
			* vector[Z]);
	return (SUCCESS);
}

int	normalise_vector(tuple new, tuple vector)
{
	float	magnitude;

	if (!new || !vector)
		return (ERROR);
	get_magnitude(&magnitude, vector);
	new[X] = vector[X] / magnitude;
	new[Y] = vector[Y] / magnitude;
	new[Z] = vector[Z] / magnitude;
	return (SUCCESS);
}

/*
Dot product calculates the angle between two vectors (e.g. as a ray bounces off the surface of an object).
It is actually the cosine of the angle between two unit vectors.
*/
int dot_product(float *dot, tuple a, tuple b)
{
    if (!*dot || !a || !b)
        return (ERROR);
    *dot = a[X] * b[X] + a[Y] * b[Y] + a[Z] * b[Z] + a[W] * b[W];
    return (SUCCESS);
}

int cross_product(tuple new, tuple a, tuple b)
{
    if (!new || !a || !b)
        return (ERROR);
    new[X] = a[Y] * b[Z] - a[Z] * b[Y];
    new[Y] = a[Z] * b[X] - a[X] * b[Z];
    new[Z] = a[X] * b[Y] - a[Y] * b[X];
    return (SUCCESS);
}