/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:21:44 by jvalkama          #+#    #+#             */
/*   Updated: 2026/03/06 14:09:07 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "matrix_invert.h"

void	determinant2(t_fl *dst, t_matrix2 matrix)
{
	*dst = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

void	determinant3(t_fl *dst, t_matrix3 matrix3)
{
	t_fl	cofactor;

	cofactor3(&cofactor, matrix3, (int []){0, 0});
	*dst = matrix3[0][0] * cofactor;
	cofactor3(&cofactor, matrix3, (int []){0, 1});
	*dst += matrix3[0][1] * cofactor;
	cofactor3(&cofactor, matrix3, (int []){0, 2});
	*dst += matrix3[0][2] * cofactor;
}

void	determinant4(t_fl *dst, t_matrix matrix4)
{
	t_fl	cofactor;

	cofactor4(&cofactor, matrix4, (int []){0, 0});
	*dst = matrix4[0][0] * cofactor;
	cofactor4(&cofactor, matrix4, (int []){0, 1});
	*dst += matrix4[0][1] * cofactor;
	cofactor4(&cofactor, matrix4, (int []){0, 2});
	*dst += matrix4[0][2] * cofactor;
	cofactor4(&cofactor, matrix4, (int []){0, 3});
	*dst += matrix4[0][3] * cofactor;
}

void	minor_determinant3(t_fl *dst, t_matrix3 matrix3, int coord[2])
{
	t_matrix2	tmp2x2;

	submatrix2(tmp2x2, matrix3, coord[ROW], coord[COLUMN]);
	determinant2(dst, tmp2x2);
}

void	minor_determinant4(t_fl *dst, t_matrix matrix4, int coord[2])
{
	t_matrix3	tmp3x3;

	submatrix3(tmp3x3, matrix4, coord[ROW], coord[COLUMN]);
	determinant3(dst, tmp3x3);
}