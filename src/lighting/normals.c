/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:28:18 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/11 11:51:56 by jvalkama         ###   ########.fr       */
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
	

int	normal_tests(void)
{
	printf("\n[ NORMALS ]\n");
	t_sphere	s;
	t_tuple		point;

	sphere_new(&s, 0);
	point_new(s.center, 0.0, 0.0, 0.0);
	point_new(point, 1, 0, 0);

	t_tuple		normal;
	normal_sphere_get(normal, &s, point);
	tuple_print(normal);

	printf("\n");

	point_new(point, 0, 1, 0);
	normal_sphere_get(normal, &s, point);
	tuple_print(normal);

	printf("\n");

	point_new(point, 0, 0, 1);
	normal_sphere_get(normal, &s, point);
	tuple_print(normal);

	printf("\n");

	point_new(point, 0, 0, 1);
	normal_sphere_get(normal, &s, point);
	tuple_print(normal);

	printf("\n");

	point_new(point, sqrtf(3)/3, sqrtf(3)/3, sqrtf(3)/3);
	normal_sphere_get(normal, &s, point);
	tuple_print(normal);

	printf("\n");

	t_tuple	*normalized = &normal;
	normalize_apply(*normalized);
	normal_sphere_get(normal, &s, point);
	tuple_print(normal);
	tuple_print(*normalized);

	printf("\n");



	printf("\n[ TRANSFORMING NORMALS ]\n");
	//sphere_new();
	//translation

	//scaling & rotation


	return 0;
}