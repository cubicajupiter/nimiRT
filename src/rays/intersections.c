/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:26:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/23 17:14:49 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

// Loops through all intersections in the scene, then returns the first
// (lowest t value) intersection.
// FIXME: UNTESTED!
int	first_intersection_get(t_xs **hit, t_vec *xs)
{
	t_xs	*tmp;
	size_t	i;

	if (!hit || !xs)
		return (ft_error(EINVAL, "hit"));
	i = 0;
	while (i < xs->len)
	{
		tmp = vec_get(xs, i);
		if (tmp->t > 0.0f)
			break ;
	}
	*hit = tmp;
	return (SUCCESS);
}

// static int	sort_ascending(void *a, void *b)
// {
// 	return ((long)*(float *)a - *(float *)b);
// }

// Loops through all objects in the scene, gets and pushes all intersections to
// the scene->xs vector array, then sorts in ascending order.
// FIXME: LIMITED TESTING!
int	scene_intersections_get(t_vec **dst, t_ray ray, t_tree *t)
{
	size_t		i;
	t_object	*object;
	t_scene		*scene;

	if (!ray || !t)
		return (ft_error(EINVAL, "intersections_get"));
	scene = t->scene;
	i = 0;
	while (i < scene->objects->len)
	{
		object = vec_get(scene->objects, i);
		object_intersections_get(scene->xs, object, ray);
		i++;
	}
	if (scene->xs->len == 0)
		return (FALSE);
	if (intersections_sort(scene->xs) != SUCCESS)
		return (ft_error(EINHERIT, "intersections_get"));
	if (dst)
		*dst = scene->xs;
	return (TRUE);
}

// Checks the object for which type it is then calls object-specific
// intersection_get function
int	object_intersections_get(t_vec *xs, t_object *object, t_ray ray)
{
	t_ray		ray2;
	t_matrix	inversion;

	if (!xs || !object || !ray)
		return (ft_error(EINVAL, "intersect_get"));

	// NOTE: AABB logic might fit here or somewhere else to simplify when objects
	// intersect one another
	matrix_invert(inversion, object->transform);
	ray_transform_get(ray2, ray, inversion);
	if (object->type == SPHERE)
		if (!sphere_intersect_get(xs, object, ray2))
			return (FALSE);
	if (object->type == PLANE)
		if (!plane_intersect_get(xs, object, ray2))
			return (FALSE);
	// if (obj->obj_type == CYLINDER)
	return (TRUE);
}

/*
	intersection_compute()
	Computes data about an intersection point on a object including the position
	the vector back to the camera, the vector of the normal at that point on the
	object and whether the camera is inside the object or not.
*/
int	intersection_compute(t_xs *hit, t_ray ray)
{
	t_fl	dot;

	if (!hit || !ray)
		return (ft_error(EINVAL, "intersection_compute"));
	if (position_get(hit->point, ray, hit->t) != SUCCESS
		|| vector_negate(hit->camera_vector, ray[DIRECTION]) != SUCCESS
		|| normal_sphere_get(hit->normal_vector,
			hit->object->sphere, hit->point) != SUCCESS
		|| vector_dot(&dot, hit->normal_vector, hit->camera_vector) != SUCCESS)
		return (ft_error(EINHERIT, "intersection_compute"));
	if (dot < 0)
	{
		hit->inside = true;
		if (vector_negate(hit->normal_vector, hit->normal_vector) != SUCCESS)
			return (ft_error(EINHERIT, "intersection_compute"));
	}
	else
		hit->inside = false;
	return (SUCCESS);
}
