/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:47:32 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/24 14:55:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

static int	no_hits(t_tree *t)
{
	t_ray		ray1;
	t_ray		ray2;
	t_ray		ray3;
	t_object	*object;
	t_fl		time;
	size_t		i;

	ray_new(ray1, (t_tuple){1, 0, 0}, (t_tuple){0, 1, 0});
	ray_new(ray2, (t_tuple){0, 0, 0}, (t_tuple){0, 1, 0});
	ray_new(ray3, (t_tuple){0, 0, -5}, (t_tuple){1, 1, 1});
	i = 0;
	while (i < t->scene->objects->len)
	{
		object = vec_get(t->scene->objects, i);
		if (object->type == CYLINDER)
		{
			cylinder_intersect_math(&time, object->cylinder, ray1);
			cylinder_intersect_math(&time, object->cylinder, ray2);
			cylinder_intersect_math(&time, object->cylinder, ray3);
		}
		i++;
	}
	return (SUCCESS);
}

static int	hits(t_tree *t)
{
	t_ray		ray1;
	t_ray		ray2;
	t_ray		ray3;
	t_object	*object;
	t_fl		time[2];
	size_t		i;

	ray_new(ray1, (t_tuple){1, 0, -5}, (t_tuple){0, 0, 1});
	ray_new(ray2, (t_tuple){0, 0, -5}, (t_tuple){0, 0, 1});
	ray_new(ray3, (t_tuple){0.5, 0, -5}, (t_tuple){0.1, 1, 1});
	i = 0;
	while (i < t->scene->objects->len)
	{
		object = vec_get(t->scene->objects, i);
		if (object->type == CYLINDER)
		{
			cylinder_intersect_math(time, object->cylinder, ray1);
			printf("t0: %f t1: %f\n", time[0], time[1]);
			cylinder_intersect_math(time, object->cylinder, ray2);
			printf("t0: %f t1: %f\n", time[0], time[1]);
			cylinder_intersect_math(time, object->cylinder, ray3);
			printf("t0: %f t1: %f\n", time[0], time[1]);
		}
		i++;
	}
	return (SUCCESS);
}

static int	normals(t_tree *t)
{
	t_tuple		point1;
	t_tuple		point2;
	t_tuple		point3;
	t_tuple		point4;
	t_tuple		vector1;
	t_tuple		vector2;
	t_tuple		vector3;
	t_tuple		vector4;
	t_object	*object;
	size_t		i;

	point_new(point1, 1, 0, 0);
	point_new(point2, 0, 5, -1);
	point_new(point3, 0, -2, 1);
	point_new(point4, -1, 1, 0);
	i = 0;
	while (i < t->scene->objects->len)
	{
		object = vec_get(t->scene->objects, i);
		if (object->type == CYLINDER)
		{
			cylinder_normal_get(vector1, object->cylinder, point1);
			tuple_print(vector1);
			cylinder_normal_get(vector2, object->cylinder, point2);
			tuple_print(vector2);
			cylinder_normal_get(vector3, object->cylinder, point3);
			tuple_print(vector3);
			cylinder_normal_get(vector4, object->cylinder, point4);
			tuple_print(vector4);
		}
		i++;
	}
	return (SUCCESS);
}

static int	truncated(t_tree *t)
{
	t_ray		ray1;
	t_ray		ray2;
	t_ray		ray3;
	t_ray		ray4;
	t_ray		ray5;
	t_ray		ray6;
	t_object	*object;
	t_fl		time;
	size_t		i;

	ray_new(ray1, (t_tuple){0, 1.5, 0, POINT}, (t_tuple){0.1, 0, 1, VECTOR});
	ray_new(ray2, (t_tuple){0, -2.5, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	ray_new(ray3, (t_tuple){0, -1, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	ray_new(ray4, (t_tuple){0, 0, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	ray_new(ray5, (t_tuple){0, 1, -5, POINT}, (t_tuple){0, 0, 1, VECTOR});
	ray_new(ray6, (t_tuple){0, 2.5, -2, POINT}, (t_tuple){0, 0, 1, VECTOR});
	i = 0;
	while (i < t->scene->objects->len)
	{
		object = vec_get(t->scene->objects, i);
		if (object->type == CYLINDER)
		{
			if (cylinder_hit_get(&time, object->cylinder, ray1))
				printf("ray1 t0: %f\n", time);
			if (cylinder_hit_get(&time, object->cylinder, ray2))
				printf("ray2 t0: %f\n", time);
			if (cylinder_hit_get(&time, object->cylinder, ray3))
				printf("ray3 t0: %f\n", time);
			if (cylinder_hit_get(&time, object->cylinder, ray4))
				printf("ray4 t0: %f\n", time);
			if (cylinder_hit_get(&time, object->cylinder, ray5))
				printf("ray5 t0: %f\n", time);
			if (cylinder_hit_get(&time, object->cylinder, ray6))
				printf("ray6 t0: %f\n", time);
		}
		i++;
	}
	return (SUCCESS);
}

int	cylinder_intersect_test(t_tree *t)
{
	no_hits(t);
	hits(t);
	normals(t);
	truncated(t);
	return (SUCCESS);
}
