/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:42:00 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/04 15:44:49 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_INVERT_H
# define MATRIX_INVERT_H

# include "miniRT.h"

void	submatrix3(t_matrix3 dst, t_matrix src, int row, int column);
void	submatrix2(t_matrix2 dst, t_matrix3 src, int row, int column);
void	determinant2(t_fl *det, t_matrix2 matrix);
void	determinant(t_fl *det, t_matrix3 matrix3, t_matrix matrix4, int width);
t_fl	minor(t_matrix matrix4, t_matrix3 matrix3, int coord[2], int size);
bool	is_invertible(t_matrix matrix4);

#endif
