/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:26:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/12 17:53:38 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include "intersections.h"

// Loops through all intersections in the scene, then returns the first
// (lowest t value) intersection.
// FIXME: UNTESTED!
int	hit(t_xs **hit, t_vec *xs)
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

static int	sort_ascending(void *a, void *b)
{
	return ((long)*(int *)a - *(int *)b);
}

// Loops through all objects in the scene, gets and pushes all intersections to
// the scene->xs vector array, then sorts in ascending order.
// FIXME: LIMITED TESTING!
int	intersections_get(t_vec **dst, t_ray ray, t_tree *t)
{
	size_t		i;
	t_object	*obj;
	t_scene		*scene;

	if (!ray || !t)
		return (ft_error(EINVAL, "intersections_get"));
	scene = t->scene;
	i = 0;
	while (i < scene->objects->len)
	{
		obj = vec_get(scene->objects, i);
		intersect_get(scene->xs, obj, ray);
		i++;
	}
	if (vec_sort(scene->xs, sort_ascending) != SUCCESS)
		return (ft_error(EINHERIT, "intersections_get"));
	if (dst)
		*dst = scene->xs;
	return (SUCCESS);
}

// Checks the object for which type it is then calls object-specific
// intersection_get function
int	intersect_get(t_vec *xs, t_object *obj, t_ray ray)
{
	if (!xs || !obj || !ray)
		return (ft_error(EINVAL, "intersect_get"));
	if (obj->obj_type == SPHERE)
		if (!sphere_intersect_get(xs, obj, ray))
			return (FALSE);
	// if (obj->obj_type == PLANE)
	// if (obj->obj_type == CYLINDER)
	return (TRUE);
}
