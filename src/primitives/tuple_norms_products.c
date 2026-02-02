/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_norms_products.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:33:14 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/02 14:25:31 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "defines.h"

/*
Magnitude is how far you would travel in a straight line if you were to go
directly from the start to the end of a vector instead of splitting the motion
up into 3 separate perpendicular movements. This is the c component in
Pythagoras's a^2 + b^2 = c^2 but in the 3D plane i.e. magnitude becomes d in
a^2 + b^2 + c^2 = d^2.
*/

int	magnitude_get(float *magnitude, const t_tuple vector)
{
	if (!magnitude || !vector)
		return (ft_error(EINVAL, "magnitude_get"));
	*magnitude = sqrtf(vector[X] * vector[X] + vector[Y] * vector[Y] + vector[Z]
			* vector[Z]);
	// Should it include W?!? Book seems unclear and AI suggests it should be there.
		//	-> I think it would depend on whether the fourth dimension is also used for something other than mode flag.
		// E.g. if W is used for transformations as johnny once suggested to me ("4th dimension") then maybe?
	// *magnitude = sqrtf(vector[X] * vector[X] + vector[Y] * vector[Y] + vector[Z]
	// 		* vector[Z] + vector[W] * vector[W]);
	return (SUCCESS);
}

/*

*/

int	normalize_get(t_tuple dst, t_tuple vector)
{
	float	magnitude;

	if (!dst || !vector)
		return (ft_error(EINVAL, "normalize_get"));
	magnitude_get(&magnitude, vector);
	dst[X] = vector[X] / magnitude;
	dst[Y] = vector[Y] / magnitude;
	dst[Z] = vector[Z] / magnitude;
	// Same here as in magnitude_get()..
	// dst[W] = vector[W] / magnitude;
	//		here the rationale for including W is to help with debugging: only vectors should be normalized, so it's always zero.
	//		If W is non-zero after normalization, something other than a vector got normalised by accident.
	return (SUCCESS);
}

int	normalize_apply(t_tuple vector)
{
	float	magnitude;

	if (!vector)
		return (ft_error(EINVAL, "normalize_apply"));
	magnitude_get(&magnitude, vector);
	vector[X] /= magnitude;
	vector[Y] /= magnitude;
	vector[Z] /= magnitude;
	// Same here as in magnitude_get()..
	// vector[W] /= magnitude;
	return (SUCCESS);
}

/*
Dot product calculates the angle between two vectors (e.g. as a ray bounces off the surface of an object).
It is actually the cosine of the angle between two unit vectors.
*/
int	vector_dot(float *dot, t_tuple a, t_tuple b)
{
	if (!*dot || !a || !b)
		return (ft_error(EINVAL, "vector_dot"));
	*dot = a[X] * b[X] + a[Y] * b[Y] + a[Z] * b[Z] + a[W] * b[W];
	return (SUCCESS);
}

int	vector_cross(t_tuple dst, t_tuple a, t_tuple b)
{
	if (!dst || !a || !b)
		return (ft_error(EINVAL, "vector_cross"));
	// Function specifically for vectors, so add this check to reject points?
	// if (dst[W] == 0)
	// 	return (FAIL);
	// 	Alternatively we could set a point to become a vector
	// if (dst[W] == 0)
	// 	dst[W] = 1;
	dst[X] = a[Y] * b[Z] - a[Z] * b[Y];
	dst[Y] = a[Z] * b[X] - a[X] * b[Z];
	dst[Z] = a[X] * b[Y] - a[Y] * b[X];
	return (SUCCESS);
}
