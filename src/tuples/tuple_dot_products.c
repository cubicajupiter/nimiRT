/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_dot_products.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:40:06 by jvalkama          #+#    #+#             */
/*   Updated: 2026/03/04 14:50:10 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//POTENTIAL POINT OF OPTIMISATION: remove most vector and point W stuff: those of it that do nothing but provide debug utility.
//particularly after debugging, W values are mostly dead weight.

/*
Dot product calculates the cosine of the angle between two (unit) vectors.
*/
int	vector_dot(t_fl *dot, t_tuple a, t_tuple b)
{
	if (!dot || !a || !b)
		return (ft_error(EINVAL, "vector_dot"));
	*dot = a[X] * b[X] + a[Y] * b[Y] + a[Z] * b[Z] + a[W] * b[W];
	return (SUCCESS);
}

/*
Dot product selective calculates the dot product between two of the angles of a vector,
ignoring the selected vector.
*/
int	vector_dot_selective(t_fl *dot, t_tuple a, t_tuple b, int ignore)
{
	if (!dot || !a || !b)
		return (ft_error(EINVAL, "vector_dot"));
	if (ignore == X)
		*dot = a[Y] * b[Y] + a[Z] * b[Z] + a[W] * b[W];
	if (ignore == Y)
		*dot = a[X] * b[X] + a[Z] * b[Z] + a[W] * b[W];
	if (ignore == Z)
		*dot = a[X] * b[X] + a[Y] * b[Y] + a[W] * b[W];
	return (SUCCESS);
}