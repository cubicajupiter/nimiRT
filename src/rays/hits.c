/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:56:22 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/01 11:02:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// scene_hit_get()
// Casts a ray, loops through all world objects and finds intersections. If a
// found intersection has a lower t value (closer to the ray origin) then the
// result is updated.
int	ray_to_scene_hit_get(t_xs *hit, t_ray ray, t_scene *s)
{
	t_object	*object;
	t_xs		result;
	t_fl		t;
	size_t		i;

	if (!hit || !ray || !s)
		return (ft_error(EINVAL, "scene_hit_get"));
	result.t = -1.0f;
	result.object = NULL;
	i = 0;
	while (i < s->objects->len)
	{
		object = vec_get(s->objects, i++);
		if (object_hit_get(&t, object, ray)
			&& (result.t < 0.0f || t < result.t))
		{
			result.object = object;
			result.t = t;
		}
	}
	if (result.t < 0.0f)
		return (FALSE);
	hit->t = result.t;
	hit->object = result.object;
	return (TRUE);
}

// Checks the object for which type it is then calls object-specific
// intersection_get function
int	object_hit_get(t_fl *t, t_object *object, t_ray ray)
{
	if (!t || !object || !ray)
		return (ft_error(EINVAL, "object_hit_get"));
	if (object->type == SPHERE)
		return (sphere_hit_get(t, object->sphere, ray));
	if (object->type == PLANE)
		return (plane_hit_get(t, object->plane, ray));
	if (object->type == CYLINDER)
		return (cylinder_hit_get(t, object->cylinder, ray));
	return (FALSE);
}

// closest_forward_hit_get()
// Gets the value of the closest hit from 2 provided values t_fl time[2]
// Useful function for handling objects such as t_sphere and t_cylinder which
// necessarily return two intersections if hit, but when the API only needs the
// value with the lowest t value (i.e. closest hit).
int	closest_forward_hit_get(t_fl *dst, t_fl *time)
{
	if (!dst || !time)
		return (ft_error(EINVAL, "closest_hit_get"));
	// printf("dst: %f time[0]: %f time[1]%f\n", *dst, time[0], time[1]);
	if (time[0] > 0.0f && time[1] > 0.0f)
	{
		if (time[0] < time[1])
			*dst = time[0];
		else
			*dst = time[1];
	}
	else if (time[0] > 0.0f)
		*dst = time[0];
	else if (time[1] > 0.0f)
		*dst = time[1];
	else
		return (FALSE);
	return (TRUE);
}
