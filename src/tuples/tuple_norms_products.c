/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_norms_products.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:33:14 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/06 10:47:45 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

/*
Magnitude is how far you would travel in a straight line if you were to go
directly from the start to the end of a vector instead of splitting the motion
up into 3 separate perpendicular movements. This is the c component in
Pythagoras's a^2 + b^2 = c^2 but in the 3D plane i.e. magnitude becomes d in
a^2 + b^2 + c^2 = d^2.
*/

int	magnitude_get(t_fl *magnitude, const t_tuple vector)
{
	if (!magnitude || !vector)
		return (ft_error(EINVAL, "magnitude_get"));
	*magnitude = sqrtf(vector[X] * vector[X] 
					+ vector[Y] * vector[Y] 
					+ vector[Z] * vector[Z]);
	return (SUCCESS);
}

int	normalize_get(t_tuple dst, t_tuple vector)
{
	t_fl	magnitude;

	if (!dst || !vector)
		return (ft_error(EINVAL, "normalize_get"));
	magnitude_get(&magnitude, vector);
	dst[X] = vector[X] / magnitude;
	dst[Y] = vector[Y] / magnitude;
	dst[Z] = vector[Z] / magnitude;
	return (SUCCESS);
}

int	normalize_apply(t_tuple vector)
{
	t_fl	magnitude;

	if (!vector)
		return (ft_error(EINVAL, "normalize_apply"));
	magnitude_get(&magnitude, vector);
	vector[X] /= magnitude;
	vector[Y] /= magnitude;
	vector[Z] /= magnitude;
	return (SUCCESS);
}

/*
Dot product calculates the cosine of the angle between two (unit) vectors.
*/
int	vector_dot(t_fl *dot, t_tuple a, t_tuple b)
{
	if (!dot || !a || !b)
		return (ft_error(EINVAL, "vector_dot"));
	*dot = a[X] * b[X] + a[Y] * b[Y] + a[Z] * b[Z] + a[W] * b[W];
	return (SUCCESS);
}

int	vector_cross(t_tuple dst, t_tuple a, t_tuple b)
{
	if (!dst || !a || !b)
		return (ft_error(EINVAL, "vector_cross"));
	dst[X] = a[Y] * b[Z] - a[Z] * b[Y];
	dst[Y] = a[Z] * b[X] - a[X] * b[Z];
	dst[Z] = a[X] * b[Y] - a[Y] * b[X];
	return (SUCCESS);
}
