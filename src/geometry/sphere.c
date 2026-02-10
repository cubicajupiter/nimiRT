/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:22:36 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/10 14:20:02 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	sphere_new(t_sphere *dst, t_tuple center)
{
	static int		id = 0;

	id++;
	dst->id = id;
	tuple_copy(dst->center, center);
	id_matrix(dst->transform);
	return (SUCCESS);
}

int	sphere_transform_set(t_sphere *sphere, t_matrix transformation)
{
	if (!transformation || !sphere)
		return (ft_error(EINVAL, "sphere_transform_set"));
	matrix_copy(sphere->transform, transformation);
	return (SUCCESS);
}