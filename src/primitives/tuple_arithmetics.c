/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_arithmetics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:27:35 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 15:19:17 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	add_tuples(tuple new, tuple const a, const tuple b)
{
	if (!new || !a || !b)
		return (ERROR);
	new[X] = a[X] + b[X];
	new[Y] = a[Y] + b[Y];
	new[Z] = a[Z] + b[Z];
	new[W] = a[W] + b[W];
	return (SUCCESS);
}

int	subract_tuples(tuple new, tuple a, const tuple b)
{
	if (!new || !a || !b)
		return (ERROR);
	new[X] = a[X] - b[X];
	new[Y] = a[Y] - b[Y];
	new[Z] = a[Z] - b[Z];
	new[W] = a[W] - b[W];
	return (SUCCESS);
}

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
