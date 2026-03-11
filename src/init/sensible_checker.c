/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sensible_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:55:16 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/10 16:10:34 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

static bool	sensible_point(t_tuple point)
{
	if (point[X] > MAX_RENDER_SIZE
		|| point[Y] > MAX_RENDER_SIZE
		|| point[Z] > MAX_RENDER_SIZE
		|| point[X] < -MAX_RENDER_SIZE
		|| point[Y] < -MAX_RENDER_SIZE
		|| point[Z] < -MAX_RENDER_SIZE)
		return (false);
	return (true);
}

static bool	sensible_transform(t_matrix transform)
{
	if (transform[0][3] > MAX_RENDER_SIZE
		|| transform[1][3] > MAX_RENDER_SIZE
		|| transform[2][3] > MAX_RENDER_SIZE
		|| transform[0][3] < -MAX_RENDER_SIZE
		|| transform[1][3] < -MAX_RENDER_SIZE
		|| transform[2][3] < -MAX_RENDER_SIZE)
		return (false);
	return (true);
}

static bool	sensible_sphere(t_sphere *sphere)
{
	if (!sensible_transform(sphere->transform))
		return (rt_max_size("sphere coordinates"));
	if (sphere->radius > MAX_RENDER_SIZE)
		return (rt_max_size("sphere radius"));
	return (true);
}

static bool	sensible_cylinder(t_cylinder *cylinder)
{
	if (!sensible_transform(cylinder->transform))
		return (rt_max_size("cylinder coordinates"));
	if (cylinder->radius > MAX_RENDER_SIZE)
		return (rt_max_size("cylinder radius"));
	if (cylinder->height > MAX_RENDER_SIZE)
		return (rt_max_size("cylinder height"));
	return (true);
}

bool	values_make_sense(t_scene *s)
{
	t_object	*object;
	bool		flag;
	size_t		i;

	if (!s)
		return (false);
	flag = true;
	i = 0;
	if (!sensible_point(s->camera.ray[ORIGIN]))
		return (rt_max_size("camera coordinates"));
	if (!sensible_point(s->light.point))
		return (rt_max_size("light coordinates"));
	while (i < s->objects->len && flag == true)
	{
		object = vec_get(s->objects, i++);
		if (object->type == PLANE)
			if (!sensible_transform(object->plane->transform))
				return (rt_max_size("plane coordinates"));
		if (object->type == SPHERE)
			flag = sensible_sphere(object->sphere);
		if (object->type == CYLINDER)
			flag = sensible_cylinder(object->cylinder);
	}
	return (flag);
}
