/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:50:05 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/04 14:39:09 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "stdbool.h"

/*
Currently compares all float values by reference to FLT_EQUAL.
However, for very large floats,
	epsilon may have to scale respectively to maintain precision.
*/
bool	is_float_equal(t_fl a, t_fl b)
{
	if (fabsf(a - b) < EPSILON)
		return (true);
	return (false);
}
