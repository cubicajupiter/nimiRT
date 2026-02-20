/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:55:38 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/20 14:22:20 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
Multiplication/division_get creates a new result vector,
whereas Multiplication/division_apply modifies the original vector in place.
*/

int	vector_multiply_get(t_tuple dst, const t_fl scalar, t_tuple vector)
{
	if (!dst || !vector)
		return (ft_error(EINVAL, "vector_multiply_get"));
	dst[X] = vector[X] * scalar;
	dst[Y] = vector[Y] * scalar;
	dst[Z] = vector[Z] * scalar;
	return (SUCCESS);
}

int	vector_divide_get(t_tuple dst, const t_fl scalar, t_tuple vector)
{
	if (!dst || !vector)
		return (ft_error(EINVAL, "vector_divide_get"));
	dst[X] = vector[X] / scalar;
	dst[Y] = vector[Y] / scalar;
	dst[Z] = vector[Z] / scalar;
	return (SUCCESS);
}

int	vector_multiply_apply(t_tuple dst, const t_fl scalar)
{
	if (!dst)
		return (ft_error(EINVAL, "vector_multiply_apply"));
	dst[X] *= scalar;
	dst[Y] *= scalar;
	dst[Z] *= scalar;
	return (SUCCESS);
}

int	vector_divide_apply(t_tuple dst, const t_fl scalar)
{
	if (!dst)
		return (ft_error(EINVAL, "vector_divide_apply"));
	dst[X] /= scalar;
	dst[Y] /= scalar;
	dst[Z] /= scalar;
	return (SUCCESS);
}
