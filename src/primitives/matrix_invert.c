/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:20:21 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/02 19:13:46 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Inverting matrices: Cofactor expansion.
Relies on these concepts: determinants, submatrices, minors & cofactors.
Determinants are needed for inverting a matrix.
Determinants are calculated from 2x2 submatrices.
2x2 submatrices are made by deleting a row & column from a 4x4 matrix to make a 3x3, then again for a 2x2.
	(This divide-and-conquer submatrix logic is in the file 'submatrix.c')
Determinants found in submatrices are called 'minors'.
*/

#include "miniRT.h"

int	matrix_invert()
{
	;
}

static int	determinant(float *det, matrix2 matrix)
{
	if (!det || !matrix)
		return (ft_error(EINVAL, "determinant"));
	*det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	return (SUCCESS);
}

static int	minor(float *det, matrix3 matrix, int row, int column)
{
	if (!det || !matrix || !row || !column)
		return (ft_error(EINVAL, "minor"));
	determinant(det, submatrix2(matrix, row, column));
	return (SUCCESS);
}

static int	cofactor(float *det, matrix3 matrix, int row, int column)
{
	if (!det || !matrix || !row || !column)
		return (ft_error(EINVAL, "cofactor"));
	minor(det, matrix, row, column);
	if (row + column % 2 == 1)
		*det *= -1;
	return (SUCCESS);
}