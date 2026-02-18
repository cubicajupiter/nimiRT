/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:30:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/18 14:15:25 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

/*
    A Ray is an array of 2 tuples: origin and direction
    Origin is a point tuple, and Direction is a vector tuple.
    But it really only becomes an actual ray with position(), which applies
	time.
*/
int	ray_new(t_ray dst, t_tuple origin, t_tuple direction)
{
	int		i;

	if (!origin || !direction || origin[W] != POINT || direction[W] != VECTOR)
		return (ft_error(EINVAL, "ray_new"));
	i = 0;
	while (i < 4)
	{
		dst[ORIGIN][i] = origin[i];
		dst[DIRECTION][i] = direction[i];
		i++;
	}
	return (SUCCESS);
}

/*
    Position is calculated by applying time to the ray.
    The ray's direction vector is scaled up/down with time to get distance
	(time can apparently be negative ;) ).
    The distance is added to the ray's origin point to get position pos.
    pos is a point tuple.
*/
int	position_get(t_tuple dst, t_ray ray, const t_fl time)
{
	t_tuple		distance;

	if (!dst || !ray)
		return (ft_error(EINVAL, "position_get"));
	vector_multiply_get(distance, time, ray[DIRECTION]);
	tuple_add_get(dst, ray[ORIGIN], distance);
	return (SUCCESS);
}

/*
	Transforming the ray is a substitute to transforming a sphere.
	Whatever transformation you want for a sphere, do the inverse of that
	transformation to a ray.
*/
int	ray_transform_get(t_ray dst, t_ray src, t_matrix transform)
{
	if (!dst || !src || !transform)
		return (ft_error(EINVAL, "ray_transform_get"));
	matrix_tuple_multiply_get(dst[ORIGIN], transform, src[ORIGIN]);
	matrix_tuple_multiply_get(dst[DIRECTION], transform, src[DIRECTION]);
	return (SUCCESS);
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
