/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:26:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/03/01 10:44:41 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// TODO: Deceide whether the following intersections_get() functions and their
// object specific counterparts are needed or not. Required if we want
// transparency and/or global lighting. Same applies to intersections_sort()
// functions.

// Loops through all intersections in the scene, then returns the first
// (lowest t value) intersection.
// int	first_intersection_get(t_xs **hit, t_vec *xs)
// {
// 	t_xs	*tmp;
// 	size_t	i;
//
// 	if (!hit || !xs)
// 		return (ft_error(EINVAL, "hit"));
// 	i = 0;
// 	while (i < xs->len)
// 	{
// 		tmp = vec_get(xs, i);
// 		if (tmp->t > 0.0f)
// 			break ;
// 	}
// 	*hit = tmp;
// 	return (SUCCESS);
// }

// Loops through all objects in the scene, gets and pushes all intersections to
// the scene->xs vector array, then sorts in ascending order.
// int	scene_intersections_get(t_vec **dst, t_ray ray, t_tree *t)
// {
// 	size_t		i;
// 	t_object	*object;
// 	t_scene		*scene;
//
// 	if (!ray || !t)
// 		return (ft_error(EINVAL, "intersections_get"));
// 	scene = t->scene;
// 	i = 0;
// 	while (i < scene->objects->len)
// 	{
// 		object = vec_get(scene->objects, i);
// 		object_intersections_get(scene->xs, object, ray);
// 		i++;
// 	}
// 	if (scene->xs->len == 0)
// 		return (FALSE);
// 	if (intersections_sort(scene->xs) != SUCCESS)
// 		return (ft_error(EINHERIT, "intersections_get"));
// 	if (dst)
// 		*dst = scene->xs;
// 	return (TRUE);
// }

// Checks the object for which type it is then calls object-specific
// intersection_get function
// int	object_intersections_get(t_vec *xs, t_object *object, t_ray ray)
// {
// 	if (!xs || !object || !ray)
// 		return (ft_error(EINVAL, "intersect_get"));
// 	// NOTE: AABB logic might fit here or somewhere else to simplify when
//	// objects intersect one another
//
// 	if (object->type == SPHERE)
// 		if (!sphere_intersect_get(xs, object, ray))
// 			return (FALSE);
// 	if (object->type == PLANE)
// 		if (!plane_intersect_get(xs, object, ray))
// 			return (FALSE);
// 	if (obj->obj_type == CYLINDER)
// 		if (!cylinder_intersect_get(xs, object, ray))
// 			return (FALSE);
// 	return (TRUE);
// }
