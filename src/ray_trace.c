/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:02:22 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/20 12:09:36 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ray_trace(t_tree *t)
{
	t_xs	hit;
	t_ray	ray;
	int		x;
	int		y;

	camera_compute(&t->scene->camera);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_ray_get(ray, &t->scene->camera, x, y);
			if (scene_hit_get(&hit, ray, t->scene))
			{
				intersection_compute(&hit, ray);
				lighting(&hit, &t->scene->light);
				pixel_put(t->image, x, y, hit.object->material.shader.combined);
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
