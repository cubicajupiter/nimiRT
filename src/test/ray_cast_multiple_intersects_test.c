/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_multiple_intersects_test.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:57:14 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/18 11:57:48 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// int	ray_trace(t_tree *t)
// {
// 	t_scene	*s;
// 	t_tuple	pos;
// 	int		x;
// 	int		y;
// 	// TODO: Calculate wall position in relation to camera later from input
// 	t_fl	wall_z 		= 	10.0;
// 	t_fl	wall_size 	= 	7.0;
// 	t_fl	pixel_size 	= 	wall_size / HEIGHT;
// 	t_fl	half 		= 	wall_size / 2;
// 	t_fl	world_x;
// 	t_fl	world_y;
// 	t_tuple	direction;
// 	t_ray	ray;
// 	t_xs	*hit_ptr = NULL;
// 	t_tuple	point;
// 	t_tuple	normal_v;
// 	t_tuple	eye_v;
// 	t_tuple	*vectors[2];
//
// 	s = t->scene;
// 	vectors[1] = &normal_v;
// 	vectors[0] = &eye_v;
// 	canvas_put(t->image, (t_trio){0});
// 	y = 0;
// 	while (y < HEIGHT) {
// 		world_y = half - pixel_size * y;
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			world_x = -half + pixel_size * x;
// 			point_new(pos, world_x, world_y, wall_z);
// 			tuple_minus_get(direction, pos, s->camera.ray[ORIGIN]);
// 			normalize_apply(direction);
// 			ray_new(ray, s->camera.ray[ORIGIN], direction);
// 			if (intersections_get(&t->scene->xs, ray, t))
// 			{
// 				first_intersection_get(&hit_ptr, t->scene->xs);
// 				position_get(point, ray, hit_ptr->t);	//These three calls compute arguments for the call to lighting()
// 				normal_sphere_get(normal_v, hit_ptr->object->sphere, point);
// 				vector_negate(eye_v, ray[DIRECTION]);
// 				lighting(&hit_ptr->object->material, &s->light, point, vectors);
// 				if (hit_ptr)
// 					pixel_put(t->image, x, y, hit_ptr->object->material.shader.combined);
// 				hit_ptr = NULL;
// 			}
// 			vec_reset(t->scene->xs);
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_loop(t->window);
// 	return (SUCCESS);
// }
