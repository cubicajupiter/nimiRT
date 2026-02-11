/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:30:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/10 15:06:34 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
    A Ray is an array of 2 tuples: origin and direction
    Origin is a point tuple, and Direction is a vector tuple.
    But it really only becomes an actual ray with position(), which applies time.
*/
int	ray_new(t_ray new, t_tuple origin, t_tuple direction)
{
	int		i;

	if (!origin || !direction)
		return (ft_error(EINVAL, "ray"));
	if (origin[W] != POINT || direction[W] != VECTOR)
		return (ft_error(EINVAL, "ray"));
	i = 0;
	while (i < 4)
	{
		new[ORIGIN][i] = origin[i];
		new[DIRECTION][i] = direction[i];
		i++;
	}
	return (SUCCESS);
}

/*
    Position is calculated by applying time to the ray.
    The ray's direction vector is scaled up/down with time to get distance (time can apparently be negative ;) ).
    The distance is added to the ray's origin point to get position pos.
    pos is a point tuple.
*/
int	position_get(t_tuple pos, t_ray ray, const t_fl time)
{
	t_tuple		distance;

	vector_multiply_get(distance, time, ray[DIRECTION]);
	tuple_add_get(pos, ray[ORIGIN], distance);
	return (SUCCESS);
}

/*
	Transforming the ray is a substitute to transforming a sphere.
	Whatever transformation you want for a sphere, do the inverse of that transformation to a ray.
*/
int	ray_transform_get(t_ray dst, t_ray src, t_matrix transform)
{
	matrix_tuple_multiply_get(dst[ORIGIN], transform, src[ORIGIN]);
	matrix_tuple_multiply_get(dst[DIRECTION], transform, src[DIRECTION]);
	return (SUCCESS);
}