/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:28:18 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/11 12:18:27 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	The NORMAL vector of an object is a UNIT VECTOR that is PERPENDICULAR to the object's surface.
	Point is the point of intersection.
	The point resides on the circumference of the sphere.
	The direction vector from the sphere's origin to this point is perpendicular to the sphere's surface.
	That direction vector is basically the normal vector,
	which is normalized to get a unit vector.
*/
int	normal_sphere_get(t_tuple dst, t_sphere *sphere, t_tuple point)
{
	tuple_minus_get(dst, point, sphere->center);
	normalize_apply(dst);
	return (SUCCESS);
}

int	normal_transform(t_tuple dst, t_sphere *sphere, t_tuple world_point)
{
	t_matrix	inverted;

	matrix_invert(inverted, sphere->transform);
	vector_multiply_get(dst, inverted, world_point);
}
