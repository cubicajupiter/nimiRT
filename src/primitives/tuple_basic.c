/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:27:35 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/02 10:21:22 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	tuple_add(tuple dst, tuple const a, const tuple b)
{
	if (!dst || !a || !b)
		return (ft_error(EINVAL, "tuple_add"));
	dst[X] = a[X] + b[X];
	dst[Y] = a[Y] + b[Y];
	dst[Z] = a[Z] + b[Z];
	dst[W] = a[W] + b[W];
	return (SUCCESS);
}

int	tuple_subtract(tuple dst, tuple a, const tuple b)
{
	if (!dst || !a || !b)
		return (ft_error(EINVAL, "tuple_subtract"));
	dst[X] = a[X] - b[X];
	dst[Y] = a[Y] - b[Y];
	dst[Z] = a[Z] - b[Z];
	dst[W] = a[W] - b[W];
	return (SUCCESS);
}

int	tuple_incr(tuple dst, const tuple increment)
{
	if (!dst || !increment)
		return (ft_error(EINVAL, "tuple_incr"));
	dst[X] += increment[X];
	dst[Y] += increment[Y];
	dst[Z] += increment[Z];
	dst[W] += increment[W];
	return (SUCCESS);
}

int	tuple_decr(tuple dst, const tuple decrement)
{
	if (!dst || !decrement)
		return (ft_error(EINVAL, "tuple_decr"));
	dst[X] -= decrement[X];
	dst[Y] -= decrement[Y];
	dst[Z] -= decrement[Z];
	dst[W] -= decrement[W];
	return (SUCCESS);
}
