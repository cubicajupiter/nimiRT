/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:42:00 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/06 16:36:15 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_INVERT_H
# define MATRIX_INVERT_H

# include "miniRT.h"

int		matrix_invert(t_matrix dst, t_matrix src);
void	cofactor3(t_fl *dst, t_matrix3 matrix3, int coord[2]);
void	cofactor4(t_fl *dst, t_matrix matrix4, int coord[2]);
bool	is_invertible(t_fl *determinant);
void	determinant2(t_fl *dst, t_matrix2 matrix);
void	determinant3(t_fl *dst, t_matrix3 matrix3);
void	determinant4(t_fl *dst, t_matrix matrix4);
void	minor_determinant3(t_fl *dst, t_matrix3 matrix3, int coord[2]);
void	minor_determinant4(t_fl *dst, t_matrix matrix4, int coord[2]);
void	submatrix2(t_matrix2 dst, t_matrix3 src, int row, int column);
void	submatrix3(t_matrix3 dst, t_matrix src, int row, int column);

#endif
