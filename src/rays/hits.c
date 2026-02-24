/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:56:22 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/24 09:59:49 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	object_hit_get(t_fl *t, t_object *object, t_ray ray);

// scene_hit_get()
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

// OLD VERSION OF IS_SHADOW_HIT() :

// int	is_shadow_hit(t_ray ray, t_scene *s, t_fl distance)
// {
// 	t_object	*object;
// 	t_fl		t;
// 	size_t		i;

// 	if (!ray || !s)
// 		return (ft_error(EINVAL, "is_shadow_hit"));
// 	i = 0;
// 	while (i < s->objects->len)
// 	{
// 		object = vec_get(s->objects, i++);
// 		if (object_hit_get(&t, object, ray))
// 		{
// 			if (t < distance)
// 				return (TRUE);
// 		}
// 	}
// 	return (FALSE);
// }


// Checks the object for which type it is then calls object-specific
// intersection_get function
int	object_hit_get(t_fl *t, t_object *object, t_ray ray)
{
	if (!t || !object || !ray)
		return (ft_error(EINVAL, "object_hit_get"));
	if (object->type == SPHERE)
		if (sphere_hit_get(t, object->sphere, ray))
			return (TRUE);
	if (object->type == PLANE)
		if (plane_hit_get(t, object->plane, ray))
			return (TRUE);
	// if (obj->obj_type == CYLINDER)
	return (FALSE);
}
