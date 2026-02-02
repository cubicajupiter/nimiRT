/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:55:32 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/02 11:36:39 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "defines.h"
# include "headers.h"

// Tests
int		throw(void);

// Window & Image
int		window_init(mlx_t **window, mlx_image_t **image);
int		window_destroy(mlx_t *window);

// Primitives
bool	is_float_equal(float a, float b);

// Tuples
int		point_new(tuple tuple, float x, float y, float z);
int		vector_new(tuple tuple, float x, float y, float z);
int		is_tuple_equal(tuple a, tuple b);
int		vector_negate(tuple dst, tuple src);

// Basic
int		tuple_add_get(tuple new, tuple const a, const tuple b);
int		tuple_add_apply(tuple dst, const tuple increment);
int		tuple_minus_get(tuple new, tuple a, const tuple b);
int		tuple_minus_apply(tuple dst, const tuple decrement);

// Scale
int		vector_multiply_get(tuple new, const float scalar, tuple vector);
int		vector_multiply_apply(tuple dst, const float scalar);
int		vector_divide_get(tuple dst, const float scalar, tuple vector);
int		vector_divide_apply(tuple dst, const float scalar);

// Normlisation and Products
int		magnitude_get(float *magn, const tuple vector);
int		normalize_get(tuple dst, tuple vector);
int		normalize_apply(tuple vector);
int		vector_dot(float *dot, tuple a, tuple b);
int		vector_cross(tuple dst, tuple a, tuple b);

// Utilities
int		ft_error(int code, const char *message);
int		tuple_print(tuple src);

#endif
