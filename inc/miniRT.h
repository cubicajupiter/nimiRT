/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:55:32 by thblack-          #+#    #+#             */
/*   Updated: 2026/01/30 14:56:02 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "defines.h"

// Primitives
bool	is_float_equal(float a, float b);

// Tuples
int	point(tuple tuple, float x, float y, float z);
int	vector(tuple tuple, float x, float y, float z);
int	is_tuple_equal(tuple a, tuple b);
int	negate_tuple(tuple new, tuple a);
int	add_tuples(tuple new, tuple const a, const tuple b);
int	subract_tuples(tuple new, tuple a, const tuple b);
int	scale_vector(tuple new, const float scalar, tuple vector);
int	get_magnitude(float *magn, const tuple vector);
int	normalise_vector(tuple new, tuple vector);

#endif
