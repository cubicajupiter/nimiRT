/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:02:22 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/01 10:22:14 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

int	ray_trace(t_tree *t)
{
	t_xs	hit;
	t_ray	ray;
	size_t	x;
	size_t	y;

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
				hit_shade(&hit, ray, t->scene);
				pixel_put(t->image, x, y, hit.object->material.shader.combined);
			}
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
