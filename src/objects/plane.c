/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:24:23 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/24 11:55:55 by jvalkama         ###   ########.fr       */
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
	if (point_new(plane->point, 0, 0, 0) != SUCCESS
		|| vector_new(plane->vector, vector[X], vector[Y], vector[Z]) != SUCCESS
		|| translation(plane->transform, pos[X], pos[Y], pos[Z]) != SUCCESS
		|| rotation_full3D(plane->transform, plane->vector) != SUCCESS
		|| vec_push(t->scene->objects, &object) != SUCCESS)
		return (ft_error(EINHERIT, "plane_new"));
	tmp = vec_get(t->scene->objects, t->scene->objects->len - 1);
	if (dst)
		*dst = tmp;
	return (SUCCESS);
}

int	plane_normal_get(t_tuple dst, t_plane *plane, t_tuple point)
{
	t_tuple		obj_point;
	t_tuple		obj_normal;

	if (!dst || !plane || !point)
		return (ft_error(EINVAL, "plane_normal_get"));
	normal_object_point_get(obj_point, plane->transform, point);
	vector_new(obj_normal, 0, 1, 0);
	normal_worldvector_get(dst, plane->transform, obj_normal);
	normalize_apply(dst);
	return (SUCCESS);
}

int	plane_hit_get(t_fl *dst, t_plane *plane, t_ray ray)
{
	t_fl		time;
	t_ray		ray2;
	t_matrix	inversion;

	if (!dst || !plane || !ray)
		return (ft_error(EINVAL, "plane_hit_get"));
	matrix_invert(inversion, plane->transform);
	ray_transform_get(ray2, ray, inversion);
	if (plane_intersect_math(&time, plane, ray2))
	{
		if (time > 0.0f)
			*dst = time;
	}
	else
		return (FALSE);
	return (TRUE);
}

int	plane_intersect_get(t_vec *xs, t_object *object, t_ray ray)
{
	t_fl		time;
	t_xs		tmp;
	t_ray		ray2;
	t_matrix	inversion;

	if (!xs || !object || !ray)
		return (ft_error(EINVAL, "plane_intersect_get"));
	matrix_invert(inversion, object->plane->transform);
	ray_transform_get(ray2, ray, inversion);
	if (plane_intersect_math(&time, object->plane, ray2))
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

static int	plane_intersect_math(t_fl *time, t_plane *plane, t_ray ray)
{
	if (!time || !plane || !ray)
		return (ft_error(EINVAL, "plane_intersect_math"));
	if (fabsf(ray[DIRECTION][Y]) < EPSILON)
		return (FALSE);
	*time = -ray[ORIGIN][Y] / ray[DIRECTION][Y]; //issue might be here
	return (TRUE);
}
