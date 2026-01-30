/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:55:32 by thblack-          #+#    #+#             */
/*   Updated: 2026/01/30 18:02:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "defines.h"

// Primitives
bool	is_float_equal(float a, float b);

// Tuples
int	point_new(tuple tuple, float x, float y, float z);
int	vector_new(tuple tuple, float x, float y, float z);
int	is_tuple_equal(tuple a, tuple b);
int	vector_negate(tuple dst, tuple src);
int	tuple_add(tuple new, tuple const a, const tuple b);
int	tuple_subtract(tuple new, tuple a, const tuple b);
int	vector_multiply(tuple new, const float scalar, tuple vector);
int	vector_divide(tuple dst, const float scalar, tuple vector);
int	magnitude_get(float *magn, const tuple vector);
int	vector_normalise(tuple dst, tuple vector);
int	vector_dot(float *dot, tuple a, tuple b);
int	vector_cross(tuple dst, tuple a, tuple b);
int	tuple_print(tuple src);

#endif
