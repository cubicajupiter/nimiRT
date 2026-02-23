/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:24:23 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/23 17:13:09 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	plane_intersect_math(t_fl *time, t_plane *plane, t_ray ray);

int	plane_new(t_object **dst, t_trio pos, t_trio vector, t_tree *t)
{
	t_plane		*plane;
	t_object	object;
	t_object	*tmp;

	if (!pos || !vector || !t)
		return (ft_error(EINVAL, "plane_new"));
	plane = NULL;
	if (ft_arena_alloc(t->a_buf, (void **)&plane, sizeof(t_plane)) != SUCCESS
		|| ft_memset(&object, 0, sizeof(t_object)) == NULL)
		return (ft_error(EINHERIT, "plane_new"));
	object.type = PLANE;
	object.plane = plane;
	material_default(&object.material);
	plane->id = t->scene->objects->len;
	if (point_new(plane->point, 0, 0, 0) != SUCCESS
		|| vector_new(plane->vector, vector[X], vector[Y], vector[Z]) != SUCCESS
		|| translation(plane->transform, pos[X], pos[Y], pos[Z]) != SUCCESS
		|| vec_push(t->scene->objects, &object) != SUCCESS)
		return (ft_error(EINHERIT, "plane_new"));
	tmp = vec_get(t->scene->objects, plane->id);
	if (dst)
		*dst = tmp;
	return (SUCCESS);
}

int	plane_intersect_get(t_vec *xs, t_object *object, t_ray ray)
{
	t_fl		time;
	t_xs		tmp;

	if (!xs || !object || !ray)
		return (ft_error(EINVAL, "plane_intersect_get"));
	if (plane_intersect_math(&time, object->sphere, ray))
	{
		tmp.t = time;
		tmp.object = object;
		if (vec_push(xs, &tmp) != SUCCESS)
			return (ft_error(EINHERIT, "plane_intersect_get"));
	}
	else
		return (FALSE);
	return (TRUE);
}

	// if ray is parallel to plane, 
		// then they will never intersect
	// if ray is coplanar with the plane (ray origin is on the plane and direction parallel to plane),
		// then we consider the ray to have missed.
		// Otherwise, there would be infinite intersections
		// but a plane is infinitely thin, so it must invisible.
	//  if ray origin is above the plane
	// if ray origin is below the plane
static int	plane_intersect_math(t_fl *time, t_plane *plane, t_ray ray)
{
	if (!time || !plane || !ray)
		return (ft_error(EINVAL, "plane_intersect_math"));
	if (fabsf(ray[DIRECTION][Y]) < EPSILON)
		return (FALSE);

	;
}