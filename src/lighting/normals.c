/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:28:18 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/24 11:52:34 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	normal_object_point_get(t_tuple dst, t_matrix transform,
				t_tuple world_point);
static int	normal_worldvector_get(t_tuple dst, t_matrix transform,
				t_tuple obj_normal);

/*
	The NORMAL vector of an object is a UNIT VECTOR that is PERPENDICULAR to
	the object's surface.
	Point is the point of intersection.
	The point resides on the circumference of the sphere.
	The direction vector from the sphere's origin to this point is
	perpendicular to the sphere's surface.
	That direction vector is basically the normal vector,
	which is normalised to get a unit vector.
*/
int	normal_get(t_tuple dst, t_object *object, t_tuple point)
{
	if (!dst || !object || !point)
		ft_error(EINVAL, "normal_get");
	if (object->type == SPHERE)
		sphere_normal_get(dst, object->sphere, point);
	else if (object->type == PLANE)
		plane_normal_get(dst, object->plane, point);
	// else if (object->type == CYLINDER)
	// 	cylinder_normal_get(dst, object->cylinder, point);
	return (SUCCESS);
}

/*
	OBJECT-TYPE AGNOSTIC!!!
			- used the same for spheres, planes and cylinders alike.
	Gets a normal vector's object point from its world point.
	Object point is the product of the world point and the inverse of the
	object's transformation.
*/
static int	normal_object_point_get(t_tuple dst, t_matrix transform,
				t_tuple world_point)
{
	t_matrix	inverse;

	if (!dst || !transform || !world_point)
		return (ft_error(EINVAL, "normal_objpoint_get"));
	matrix_invert(inverse, transform);
	matrix_tuple_multiply_get(dst, inverse, world_point);
	return (SUCCESS);
}

/*
	OBJECT-TYPE AGNOSTIC!!!
			- used the same for spheres, planes and cylinders alike.
	Transform a normal in object space to world space.
	1. Inverts the transformation.
	2. Transposes the inverse.
	3. Applies the transposed inverse to the normal in object space (converting
	it to world space normal.)
	4. Normalises the world space vector.
*/
static int	normal_worldvector_get(t_tuple dst, t_matrix transform,
				t_tuple obj_normal)
{
	t_matrix	inverse;
	t_matrix	transposed_inverse;

	if (!dst || !transform || !obj_normal)
		return (ft_error(EINVAL, "normal_worldvector_get"));
	matrix_invert(inverse, transform);
	matrix_transpose(transposed_inverse, inverse);
	matrix_tuple_multiply_get(dst, transposed_inverse, obj_normal);
	dst[W] = VECTOR;
	return (SUCCESS);
}
