/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:55:38 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/02 10:17:28 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
Multiplication/division_get creates a new result vector,
whereas Multiplication/division_apply modifies the original vector in place.
*/

int	vector_multiply_get(tuple dst, const float scalar, tuple vector)
{
	if (!dst || !vector)
		return (ft_error(EINVAL, "vector_multiply_get"));
	dst[X] = vector[X] * scalar;
	dst[Y] = vector[Y] * scalar;
	dst[Z] = vector[Z] * scalar;
	dst[X] = vector[X] * scalar;
	return (SUCCESS);
}

int	vector_divide_get(tuple dst, const float scalar, tuple vector)
{
	if (!dst || !vector)
		return (ft_error(EINVAL, "vector_divide_get"));
	dst[X] = vector[X] / scalar;
	dst[Y] = vector[Y] / scalar;
	dst[Z] = vector[Z] / scalar;
	dst[X] = vector[X] / scalar;
	return (SUCCESS);
}

int	vector_multiply_apply(tuple dst, const float scalar)
{
	if (!dst)
		return (ft_error(EINVAL, "vector_multiply_apply"));
	dst[X] *= scalar;
	dst[Y] *= scalar;
	dst[Z] *= scalar;
	dst[X] *= scalar;
	return (SUCCESS);
}

int	vector_divide_apply(tuple dst, const float scalar)
{
	if (!dst)
		return (ft_error(EINVAL, "vector_divide_apply"));
	dst[X] /= scalar;
	dst[Y] /= scalar;
	dst[Z] /= scalar;
	dst[X] /= scalar;
	return (SUCCESS);
}
