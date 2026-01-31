/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:55:38 by thblack-          #+#    #+#             */
/*   Updated: 2026/01/31 16:55:46 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	vector_multiply(tuple dst, const float scalar, tuple vector)
{
	if (!dst || !scalar || !vector)
		return (ERROR);
	dst[X] = vector[X] * scalar;
	dst[Y] = vector[Y] * scalar;
	dst[Z] = vector[Z] * scalar;
	dst[X] = vector[X] * scalar;
	return (SUCCESS);
}

int	vector_divide(tuple dst, const float scalar, tuple vector)
{
	if (!dst || !scalar || !vector)
		return (ERROR);
	dst[X] = vector[X] / scalar;
	dst[Y] = vector[Y] / scalar;
	dst[Z] = vector[Z] / scalar;
	dst[X] = vector[X] / scalar;
	return (SUCCESS);
}
