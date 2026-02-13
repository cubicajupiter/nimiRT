/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_shader_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:32:46 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/13 17:40:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	sphere_and_shade(t_tree *tree);

static int	sphere_and_shade(t_tree *tree)
{
	t_tuple		origin;			point_new(origin, 0, 0, -5);
	t_fl		wall_z 		= 	10.0;
	t_fl		wall_size 	= 	7.0;
	t_fl		pixel_size 	= 	wall_size / HEIGHT;
	t_fl		half 		= 	wall_size / 2;
	
	t_tuple		pos;
	t_xs		*hit_ptr = NULL;
	t_fl		world_x;
	t_fl		world_y;
	int			x;
	int			y;
	t_ray		ray;
	t_tuple		direction;

	t_tuple		center;		point_new(center, 0, 0, 0); 
	t_object 	*obj;
	sphere_new(&obj, center, 1.0, tree);

	color_new(obj->material.color, 1, 0.2, 1);
	
	t_tuple			light_pos; 		point_new(light_pos, -10, 10, -10);
	t_trio			light_color; 	color_new(light_color, 1, 1, 1);
	t_light 		light; 			point_light_new(&light, light_pos, light_color);

	t_tuple		point;			
	t_tuple		normal_v;
	t_tuple		eye_v;
	t_tuple		*vectors[2];

	canvas_put(tree->image, (t_trio){0});
	y = 0;
	while (y < HEIGHT) {
		world_y = half - pixel_size * y;
		x = 0;
		while (x < WIDTH)
		{
			world_x = -half + pixel_size * x;
			point_new(pos, world_x, world_y, wall_z);
			tuple_minus_get(direction, pos, origin);
			normalize_apply(direction);
			ray_new(ray, origin, direction);
			if (intersections_get(&tree->scene->xs, ray, tree))
			{
				hit(&hit_ptr, tree->scene->xs);

				position_get(point, ray, hit_ptr->t);	//These three calls compute arguments for the call to lighting()
				normal_sphere_get(normal_v, hit_ptr->object->sphere, point);
				vector_negate(eye_v, ray[DIRECTION]);
				vectors[0] = &normal_v; vectors[1] = &eye_v;
				lighting(&hit_ptr->object->material, &light, point, vectors);

				if (hit_ptr)
					pixel_put(tree->image, x, y, hit_ptr->object->material.shader.combined);
				hit_ptr = NULL;
			}
			x++;
		}
		y++;
	}
	return 0;
}

void	sphere_shader_test(t_tree *tree)
{
	window_init(&tree->window, &tree->image);
	mlx_loop_hook(tree->window, commands, tree);
	sphere_and_shade(tree);
	mlx_loop(tree->window);
	window_destroy(tree->window, tree->image);
}
