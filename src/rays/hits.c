/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:56:22 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/18 11:56:08 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	object_hit_get(t_fl *t, t_object *object, t_ray ray);

// hit_get()
// Casts a ray, loops through all world objects and finds intersections. If a
// found intersection has a lower t value (closer to the ray origin) then the
// result is updated.
// FIXME: UNTESTED!
int	scene_hit_get(t_xs *hit, t_ray ray, t_scene *s)
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
		if (sphere_hit_get(t, object, ray))
			return (TRUE);
	// if (obj->obj_type == PLANE)
	// if (obj->obj_type == CYLINDER)
	return (FALSE);
}
