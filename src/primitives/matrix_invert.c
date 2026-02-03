/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:20:21 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/03 11:49:05 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Inverting matrices: Cofactor expansion.
Relies on these concepts: determinants, submatrices, minors & cofactors.
Determinants are needed for inverting a matrix.
Determinants are calculated from 2x2 submatrices.
2x2 submatrices are made by deleting a row & column from a 4x4 matrix to make a 3x3, then again for a 2x2.
	(This divide-and-conquer submatrix logic is in the file 'submatrix.c')
The Determinants found in these submatrices are called 'minors'.
Cofactors are needed to calculate determinants for matrices larger than 2x2.
	- To calculate the cofactors, you calculate minors from submatrices.
		-- SO the minors of 4x4 matrices are the determinants of 3x3 matrices,
		-- and the minors of 3x3 are the determinants of its 2x2 matrices.
You need a matrix of cofactors, which is then transposed and finally divided by the determinant
of the original matrix.
*/

//NOTE: Make sure 4x4 -> 3x3 -> 2x2 divide-and-conquer happens correctly!!!!!!!!!!

#include "miniRT.h"

static int		determinant(float *det, float **matrix, int width);
static float	minor(float **matrix, int row, int column, int width);
static float	cofactor(float **matrix, int row, int column, int width);
static bool		is_invertible(t_matrix m);

int	matrix_invert(t_matrix dst, t_matrix src)
{
	float	det;
	int		i;
	int		j;

	if (!dst || !src)
		return (ft_error(EINVAL, "matrix_invert"));
	if (!is_invertible(src))
		return (1);
	i = 0;
	j = 0;
	det = 0.0;
	while (i < 4)
	{
		while (j < 4)
		{
			determinant(&det, src, 4)
			dst[j][i] = cofactor(src, i, j, 4) / det;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static int	determinant(float *det, float **matrix, int width)
{
	int		column;

	if (!det || !matrix || !width)
		return (ft_error(EINVAL, "determinant"));
	if (width == 2)
		*det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	else if (width > 2)
	{
		column = 0;
		while (column < width)
		{
			*det += matrix[0][column] * cofactor(matrix, 0, column, width);
		}
	}
	return (SUCCESS);
}

static float	minor(float **matrix, int row, int column, int width)
{
	float		det;

	if (width == 3)
		determinant(&det, submatrix2((t_matrix3)matrix, row, column), 2);
	else if (width == 4)
		determinant(&det, submatrix3((t_matrix)matrix, row, column), 3);
	return (det);
}

static float	cofactor(float **matrix, int row, int column, int width)
{
	float		det;

	det = minor(matrix, row, column, width);
	if (row + column % 2 == 1)
		det *= -1;
	return (det);
}

static bool	is_invertible(t_matrix matrix)
{
	float		det;
	
	det = 0.0;
	determinant(&det, matrix, 4);
	if (is_float_equal(det, 0.0))
		return (false);
	return (true);
}


int	main(void)
{
	t_matrix dst, src;

	dst = NULL; src = NULL;
	matrix_invert(dst, src);
	return 0; //TODO: TESTS AFTER EXAM!!!!!!!!!!
}