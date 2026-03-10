/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_products.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:40:06 by jvalkama          #+#    #+#             */
/*   Updated: 2026/03/09 18:44:11 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
Dot product calculates the cosine of the angle between two (unit) vectors.
*/
int	vector_dot(t_fl *dot, t_tuple a, t_tuple b)
{
	if (!dot || !a || !b)
		return (ft_error(EINVAL, "vector_dot"));
	*dot = a[X] * b[X] + a[Y] * b[Y] + a[Z] * b[Z];
	return (SUCCESS);
}

/*
Dot product selective calculates the dot product between two of the angles of
a vector, ignoring the selected vector.
*/
int	vector_dot_selective(t_fl *dot, t_tuple a, t_tuple b, int ignore)
{
	if (!dot || !a || !b)
		return (ft_error(EINVAL, "vector_dot"));
	if (ignore == X)
		*dot = a[Y] * b[Y] + a[Z] * b[Z];
	if (ignore == Y)
		*dot = a[X] * b[X] + a[Z] * b[Z];
	if (ignore == Z)
		*dot = a[X] * b[X] + a[Y] * b[Y];
	return (SUCCESS);
}

int	vector_cross(t_tuple dst, t_tuple a, t_tuple b)
{
	if (!dst || !a || !b || a[W] > VECTOR || b[W] > VECTOR)
		return (ft_error(EINVAL, "vector_cross"));
	dst[X] = a[Y] * b[Z] - a[Z] * b[Y];
	dst[Y] = a[Z] * b[X] - a[X] * b[Z];
	dst[Z] = a[X] * b[Y] - a[Y] * b[X];
	dst[W] = VECTOR;
	return (SUCCESS);
}
