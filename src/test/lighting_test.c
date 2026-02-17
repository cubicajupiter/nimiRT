/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:46:14 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 17:39:48 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "lighting.h"

int	lighting_test(t_tree *tree)
{
	t_tuple		c;		point_new(c, 0, 0, 0);
	t_fl		ra	= 	1.0;
	t_object	*s;		sphere_new(&s, c, ra, tree);

	printf("\n[ NORMALS ]\n");
	t_tuple		point;

	point_new(point, 1, 0, 0);

	t_tuple		normal;
	normal_sphere_get(normal, s->sphere, point);
	tuple_print(normal);

	printf("\n");

	point_new(point, 0, 1, 0);
	normal_sphere_get(normal, s->sphere, point);
	tuple_print(normal);

	printf("\n");

	point_new(point, 0, 0, 1);
	normal_sphere_get(normal, s->sphere, point);
	tuple_print(normal);

	printf("\n");

	point_new(point, sqrtf(3)/3, sqrtf(3)/3, sqrtf(3)/3);
	normal_sphere_get(normal, s->sphere, point);
	tuple_print(normal);

	printf("\n");

	t_tuple	*normalized = &normal;
	normalize_apply(*normalized);
	normal_sphere_get(normal, s->sphere, point);
	tuple_print(normal);
	tuple_print(*normalized);

	printf("\n");



	printf("\n[ TRANSFORMING NORMALS ]\n");
	//Translation
	translation(s->sphere->transform, 0, 1, 0);
	t_tuple		p;	point_new(p, 0, 1.70711, -0.70711);
	t_tuple		n;		normal_sphere_get(n, s->sphere, p);
	tuple_print(n);


	//Scaling + rotation
	t_matrix	t;		scaling(t, 1, 0.5, 1);
	t_matrix	t2;		rotation_z(t2, PI/5);
	matrix_multiply_get(s->sphere->transform, t, t2);
	point_new(p, 0, sqrtf(2)/2, -sqrtf(2)/2);
	normal_sphere_get(n, s->sphere, p);
	tuple_print(n);


	printf("\n[ BASIC REFLECTIONS ]\n");
	//45 angle
	t_tuple		v;		vector_new(v, 1, -1, 0);
	t_tuple		n2;		vector_new(n2, 0, 1, 0);
	t_tuple		r;		reflection_get(r, v, n2);
	tuple_print(r);

	//slanted surface
	vector_new(v, 0, -1, 0);
	vector_new(n2, sqrtf(2)/2, sqrtf(2)/2, 0);
	reflection_get(r, v, n2);
	tuple_print(r);


	printf("\n[ LIGHT SOURCE ]\n");
	//Point light attributes
	t_trio			color; 		color_new(color, 1, 1, 1);
	t_tuple			location;	point_new(location, 0, 0, 0);
	t_light			light;		point_light_new(&light, location, color);
	tuple_print(light.point);
	color_print(light.color);


	printf("\n[ MATERIALS ]\n");
	//default material
	t_material		mat;			material_new(&mat);
	color_print(mat.color);
	printf("Default material values: %f \t %f \t %f \t %f\n", mat.ambi_light, mat.diff_light, mat.spec_light, mat.shine);

	sphere_new(NULL, (t_trio){0}, 1.0, tree);
	t_object		*object = 		vec_get(tree->scene->objects, 1);	//get the second initialised sphere (the first one to be initialised was s)
	object->material.ambi_light = 	1.0;
	printf("ambient light after assigning: %f\n", object->material.ambi_light);


	printf("\n[ LIGHTING ]\n");
	t_material		m;			material_new(&m);
	t_tuple			pos;		point_new(pos, 0, 0, 0);

	//light directly behind camera
	t_tuple			eye_v1;		vector_new(eye_v1, 0, 0, -1);
	t_tuple			norm_v1;	vector_new(norm_v1, 0, 0, -1);
	t_tuple			location1;	point_new(location1, 0, 0, -10);
	t_trio			color2;		color_new(color2, 1, 1, 1);
	t_light			light2;		point_light_new(&light2, location1, color2);
	lighting(&m, &light2, pos, (t_tuple *[2]){&eye_v1, &norm_v1});
	printf("\n[ light directly behind camera ]\n");
	color_print(m.shader.combined);

	//camera in 45 degree angle
	t_tuple			eye_v2;		vector_new(eye_v2, 0, sqrtf(2)/2, -sqrtf(2)/2);
	t_tuple			norm_v2;	vector_new(norm_v2, 0, 0, -1);
	lighting(&m, &light2, pos, (t_tuple *[2]){&eye_v2, &norm_v2});
	printf("\n[ camera in 45 degree angle ]\n");
	color_print(m.shader.combined);

	//light in 45 degree angle
	t_tuple			eye_v3;		vector_new(eye_v3, 0, 0, -1);
	t_tuple			norm_v3;	vector_new(norm_v3, 0, 0, -1);
	t_tuple			location2;	point_new(location2, 0, 10, -10);
	tuple_copy(light2.point, location2);
	lighting(&m, &light2, pos, (t_tuple *[2]){&eye_v3, &norm_v3});
	printf("\n[ light in 45 degree angle ]\n");
	color_print(m.shader.combined);

	//light and camera in 45 degree angle 
	t_tuple			eye_v4;		vector_new(eye_v4, 0, -sqrtf(2)/2, -sqrtf(2)/2);
	t_tuple			norm_v4;	vector_new(norm_v4, 0, 0, -1);
	lighting(&m, &light2, pos, (t_tuple *[2]){&eye_v4, &norm_v4});
	printf("\n[ light and camera in 45 degree angle  ]\n");
	color_print(m.shader.combined);

	//light is behind the object
	t_tuple			eye_v5;		vector_new(eye_v5, 0, 0, -1);
	t_tuple			norm_v5;	vector_new(norm_v5, 0, 0, -1);
	t_tuple			location3;	point_new(location3, 0, 0, 10);
	tuple_copy(light2.point, location3);
	lighting(&m, &light2, pos, (t_tuple *[2]){&eye_v5, &norm_v5});
	printf("\n[ light is behind the object ]\n");
	color_print(m.shader.combined);


	return 0;
}
