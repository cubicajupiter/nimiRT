/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:05:52 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/09 17:06:19 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

void	ray_trace(t_tree *t, t_scene *s, size_t i)
{
	t_xs	hit;
	t_ray	ray;
	size_t	x;
	size_t	y;

	camera_compute(&s->camera);
	y = i;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_ray_get(ray, &s->camera, x, y);
			if (ray_to_scene_hit_get(&hit, ray, s))
			{
				hit_shade(&hit, ray, s);
				pixel_put(t->image, x, y, hit.object->material.shader.combined);
			}
			x++;
		}
		y += DEFAULT_THREADS;
	}
}
