/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:55:32 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/04 14:46:49 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "defines.h"
# include "headers.h"

// Tests
int		throw(t_tree *t);

// Window & Image
int		window_init(mlx_t **window, mlx_image_t **image);
int		window_destroy(mlx_t *window);
int		canvas_put(mlx_image_t *image, t_trio color);
int		pixel_put(mlx_image_t *image, t_uint x, t_uint y, t_trio c);
bool    is_pixel_on_image(t_uint x, t_uint y);

// Primitives
bool    is_float_equal(float a, float b);

// Matrices
int 	matrix_compare(t_matrix a, t_matrix b);
int 	matrix_multiply(t_matrix dst, t_matrix a, t_matrix b);
int 	matrix_tuple_multiply(t_tuple dst, t_matrix a, t_tuple b);
int 	matrix_transpose(t_matrix dst, t_matrix src);
int     matrix_identity_get(t_matrix identity);

// Matrix Invert
int		matrix_invert(t_matrix dst, t_matrix src);
t_fl	cofactor(t_matrix matrix4, t_matrix3 matrix3, int coord[2], int width);
t_fl	minor(t_matrix matrix4, t_matrix3 matrix3, int coord[2], int width);
bool	is_invertible(t_matrix matrix4);
void	submatrix3(t_matrix3 dst, t_matrix src, int row, int column);
void	submatrix2(t_matrix2 dst, t_matrix3 src, int row, int column);
void	determinant2x2(t_fl *det, t_matrix2 matrix);
void	determinant(t_fl *det, t_matrix3 matrix3, t_matrix matrix4, int width);

//FIX: REMOVE BEFORE EVALS!!!!!!!!!!!!!!!!!!!!!!!!!!
int test_matrix(void);
void    test_matrix_basics(void);

// Tuples
int		point_new(t_tuple tuple, float x, float y, float z);
int		vector_new(t_tuple tuple, float x, float y, float z);
int		is_tuple_equal(t_tuple a, t_tuple b);
int		vector_negate(t_tuple dst, t_tuple src);

// Basic
int		tuple_add_get(t_tuple new, t_tuple const a, const t_tuple b);
int		tuple_add_apply(t_tuple dst, const t_tuple increment);
int		tuple_minus_get(t_tuple new, t_tuple a, const t_tuple b);
int		tuple_minus_apply(t_tuple dst, const t_tuple decrement);

// Scale
int		vector_multiply_get(t_tuple new, const float scalar, t_tuple vector);
int		vector_multiply_apply(t_tuple dst, const float scalar);
int		vector_divide_get(t_tuple dst, const float scalar, t_tuple vector);
int		vector_divide_apply(t_tuple dst, const float scalar);

// Normlisation and Products
int		magnitude_get(float *magn, const t_tuple vector);
int		normalize_get(t_tuple dst, t_tuple vector);
int		normalize_apply(t_tuple vector);
int		vector_dot(float *dot, t_tuple a, t_tuple b);
int		vector_cross(t_tuple dst, t_tuple a, t_tuple b);

// Color
int		color_trio_to_uint(uint32_t *color, t_trio c);

// Utilities
int		ft_error(int code, const char *message);
int		tuple_print(t_tuple src);


#endif
