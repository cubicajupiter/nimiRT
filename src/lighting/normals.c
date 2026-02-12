/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:28:18 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/11 17:16:11 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	normal_objpoint_transform(t_tuple dst, t_sphere *sphere, t_tuple world_point);
static int	normal_worldvec_transform(t_tuple dst, t_sphere *sphere, t_tuple obj_normal);

/*
	The NORMAL vector of an object is a UNIT VECTOR that is PERPENDICULAR to the object's surface.
	Point is the point of intersection.
	The point resides on the circumference of the sphere.
	The direction vector from the sphere's origin to this point is perpendicular to the sphere's surface.
	That direction vector is basically the normal vector,
	which is normalised to get a unit vector.
*/


int	normal_sphere_get(t_tuple dst, t_sphere *sphere, t_tuple point)
{
	t_tuple		obj_point;
	t_tuple		obj_normal;

	if (!dst || !sphere || !point)
		return (ft_error(EINVAL, "normal_sphere_get"));
	normal_objpoint_transform(obj_point, sphere, point);
	tuple_minus_get(obj_normal, obj_point, sphere->center);
	normal_worldvec_transfrom(dst, sphere, obj_normal);
	normalize_apply(dst);
	return (SUCCESS);
}

/*
	Gets a normal vector's object point from its world point.
	Object point is the product of the world point and the inverse of the object's transformation.
*/
static int	normal_objpoint_transform(t_tuple dst, t_sphere *sphere, t_tuple world_point)
{
	t_matrix	inverse;

	if (!dst || !sphere || !world_point)
		return (ft_error(EINVAL, "normal_opoint_transform"));
	matrix_invert(inverse, sphere->transform);
	matrix_tuple_multiply_get(dst, inverse, world_point);
	return (SUCCESS);
}

/*
	Transform a normal in object space to world space.
	1. Inverts the transformation.
	2. Transposes the inverse.
	3. Applies the transposed inverse to the normal in object space (converting it to world space normal.)
	4. Normalises the world space vector.
*/
static int	normal_worldvec_transform(t_tuple dst, t_sphere *sphere, t_tuple obj_normal)
{
	t_matrix	inverse;
	t_matrix	transposed_inverse;

	if (!dst || !sphere || !obj_normal)
		return (ft_error(EINVAL, "normal_wvector_transform"));
	matrix_invert(inverse, sphere->transform);
	matrix_transpose(transposed_inverse, inverse);
	matrix_tuple_multiply_get(dst, transposed_inverse, obj_normal);
	normalize_apply(dst);
	dst[W] = 0;
	return (SUCCESS);
}