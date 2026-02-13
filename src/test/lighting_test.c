/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:46:14 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 09:58:53 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "lighting.h"

int	lighting_test(t_tree *tree)
{
	t_tuple		c;		point_new(&c, 0, 0, 0);
	t_fl		ra	= 	1.0;
	t_sphere	*s;		sphere_new(&s, c, ra, tree);



	printf("\n[ NORMALS ]\n");
	t_tuple		point;
	
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
	t_matrix	t;		translation(t, 0, 1, 0);
	t_tuple		pos;	point_new(pos, 0, 1.70711, -0.70711);
	sphere_transform_set(s, t);
	t_tuple		n;		normal_sphere_get(n, s, pos);
	tuple_print(n);


	//Scaling + rotation
	scaling(t, 1, 0.5, 1);
	t_matrix	t2;		rotation_z(t2, PI/5);
	t_matrix	T;		matrix_multiply_get(T, t, t2);
	sphere_transform_set(s, T);
	point_new(pos, 0, sqrtf(2)/2, -sqrtf(2)/2);
	normal_sphere_get(n, s, pos);
	tuple_print(n);


	printf("\n[ BASIC REFLECTIONS ]\n");
	//45 angle
	t_tuple		v;		vector_new(v, 1, -1, 0);
	t_tuple		n;		vector_new(n, 0, 1, 0);
	t_tuple		r;		reflection_get(r, v, n);
	tuple_print(r);

	//slanted surface
	vector_new(v, 0, -1, 0);
	vector_new(n, sqrtf(2)/2, sqrtf(2)/2, 0);
	reflection(r, v, n);
	tuple_print(r);


	printf("\n[ LIGHT SOURCE ]\n");
	//Point light attributes
	t_trio		color; 		color_new(color, 1, 1, 1);
	t_tuple		location;	point_new(location, 0, 0, 0);
	t_light		light;		point_light_new(&light, location, color);
	tuple_print(light.pos);
	color_print(light.intensity);


	printf("\n[ MATERIALS ]\n");
	//default material
	t_material		mat;			material_new(&mat);
	color_print(mat.color);
	printf("Default material values: %f \t %f \t %f \t %f\n", mat.ambi_light, mat.diff_light, mat.ambi_light, mat.shine);

	t_sphere		*sphere;		sphere_new(sphere, (t_trio){0}, 1.0, tree);
	t_object		*object = 		vec_get(tree->scene->objects, 1);	//get the second initialised sphere (the first one to be initialised was s)
	object->material.ambi_light = 	1.0;
	printf("ambient light after assigning: %f\n", object->material.ambi_light);


	//Lighting
	t_material		m;			material_new(&m);
	t_tuple			pos;		point_new(pos, 0, 0, 0);

	t_tuple			eye_v1;		vector_new(eye_v1, 0, 0, -1);
	t_tuple			norm_v1;	vector_new(norm_v1, 0, 0, -1);
	t_tuple			location1;	point_new(location1, 0, 0, -10);
	t_trio			color;		color_new(color, 1, 1, 1);
	t_light			light;		point_light_new(&light, location1, color);
	lighting(m, );

	t_tuple			eye_v2;		vector_new(eye_v2, 0, sqrtf(2)/2, -sqrtf(2)/2);
	t_tuple			norm_v2;	vector_new(norm_v2, 0, 0, -1);
	lighting();

	t_tuple			eye_v3;		vector_new(eye_v3, 0, 0, -1);
	t_tuple			norm_v3;	vector_new(norm_v3, 0, 0, -1);
	t_tuple			location2;	point_new(location2, 0, 10, -10);
	tuple_copy(light.pos, location2);
	lighting();

	t_tuple			eye_v4;		vector_new(eye_v4, 0, -sqrtf(2)/2, -sqrtf(2)/2);
	t_tuple			norm_v4;	vector_new(norm_v4, 0, 0, 1);
	lighting();

	t_tuple			eye_v5;		vector_new(eye_v5, 0, 0, -1);
	t_tuple			norm_v5;	vector_new(norm_v5, 0, 0, -1);
	t_tuple			location3;	point_new(location3, 0, 0, 10);
	tuple_copy(light.pos, location3);
	lighting();


	return 0;
}
