/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:46:14 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/12 16:30:11 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	normal_tests(t_tree *t)
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
	//Translation
	sphere_new();
	translation();
	sphere_transform_set();

	point_new();
	normal_sphere_get()


	//Scaling + rotation
	scaling();
	rotation_z();
	sphere_transform_set();

	point_new();
	normal_sphere_get();


	//Reflections
	vector_new();
	vector_new();
	reflection();

	vector_new();
	vector_new();
	reflection();


	//Light source
	color_new();
	point_new();
	point_light_new();


	//Materials
	material_new();

	sphere_new();

	sphere->material();


	//Lighting
	material_new();
	point_new();
	vector_new();
	vector_new();
	point_light_new();
	lighting();

	material_new();
	point_new();
	vector_new();
	vector_new();
	point_light_new();
	lighting();

	material_new();
	point_new();
	vector_new();
	vector_new();
	point_light_new();
	lighting();

	material_new();
	point_new();
	vector_new();
	vector_new();
	point_light_new();
	lighting();

	material_new();
	point_new();
	vector_new();
	vector_new();
	point_light_new();
	lighting();


	return 0;
}
