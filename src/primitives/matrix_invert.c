/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:20:21 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/03 18:57:31 by jvalkama         ###   ########.fr       */
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
#include "matrix_invert.h"

static float	minor(t_matrix matrix4, t_matrix3 matrix3,  int coord[2], int width);
static bool		is_invertible(t_matrix m);

int	matrix_invert(t_matrix dst, t_matrix src)
{
	t_fl	det;
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
			determinant(&det, NULL, src, 4);
			dst[j][i] = cofactor(src, NULL, (int []){i, j}, 4) / det;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static t_fl	minor(t_matrix matrix4, t_matrix3 matrix3, int coord[2], int width)
{
	t_fl		det;
    t_matrix2   tmp2x2;
    t_matrix3   tmp3x3;

    det = 0.0;
	if (width == 3)
    {
        printf("determinant in minor before logic: %f\n", det);
        submatrix2(tmp2x2, matrix3, coord[ROW], coord[COLUMN]);
        determinant2x2(&det, tmp2x2);
    }
	else if (width == 4)
    {
        submatrix3(tmp3x3, matrix4, coord[ROW], coord[COLUMN]);
        determinant(&det, tmp3x3, NULL, 3);
    }
    printf("determinant before return: %f\n", det);
	return (det);
}

t_fl	cofactor(t_matrix matrix4, t_matrix3 matrix3, int coord[2], int width)
{
	t_fl		det;

    if (width == 4)
	    det = minor(matrix4, NULL, coord, width);
    if (width == 3)
        det = minor(NULL, matrix3, coord, width);
    if (coord[ROW] + coord[COLUMN] % 2 == 1)
        det *= -1;
    return (det);
}

static bool	is_invertible(t_matrix matrix4)
{
	t_fl		det;
	
	det = 0.0;
	determinant(&det, NULL, matrix4, 4);
	if (is_float_equal(det, 0.0))
		return (false);
	return (true);
}

int test_matrix(void)
{
    printf("[ DETERMINANTS ]\n");
    t_matrix2   m2;
    t_fl        det;
    
    m2[0][0] = 1.0;
    m2[0][1] = 5.0;
    m2[1][0] = -3.0;
    m2[1][1] = 2.0;
    determinant2x2(&det, m2);
    printf("determinant: %f\n", det);


    printf("\n[ SUBMATRICES ]\n");
    t_matrix3   m3;
    t_matrix    m4;

    m3[0][0] = 1.0;
    m3[0][1] = 5.0;
    m3[0][2] = 0.0;
    m3[1][0] = -3.0;
    m3[1][1] = 2.0;
    m3[1][2] = 7.0;
    m3[2][0] = 0.0;
    m3[2][1] = 6.0;
    m3[2][2] = -3.0;

    m4[0][0] = -6.0;
    m4[0][1] = 1.0;
    m4[0][2] = 1.0;
    m4[0][3] = 6.0;
    m4[1][0] = -8.0;
    m4[1][1] = 5.0;
    m4[1][2] = 8.0;
    m4[1][3] = 6.0;
    m4[2][0] = -1.0;
    m4[2][1] = 0.0;
    m4[2][2] = 8.0;
    m4[2][3] = 2.0;
    m4[3][0] = -7.0;
    m4[3][1] = 1.0;
    m4[3][2] = -1.0;
    m4[3][3] = 1.0;

    int         i = 0;
    int         j;
    printf("\tm2:\n");
    submatrix2(m2, m3, 0, 2);
    while (i < 2) {
        j = 0;
        while (j < 2) {
            printf("%f ", m2[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("\n\tAnd m3:\n");
    submatrix3(m3, m4, 2, 1);
    i = 0;
    while (i < 3) {
        j = 0;
        while (j < 3) {
            printf("%f ", m3[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }


    printf("\n[ MINORS ]\n");
    t_matrix2   m2b;
    t_fl        det2;

    m3[0][0] = 3.0;
    m3[0][1] = 5.0;
    m3[0][2] = 0.0;
    m3[1][0] = 2.0;
    m3[1][1] = -1.0;
    m3[1][2] = -7.0;
    m3[2][0] = 6.0;
    m3[2][1] = -1.0;
    m3[2][2] = 5.0;

    submatrix2(m2b, m3, 1, 0);
    determinant2x2(&det2, m2b);
    printf("Determinant without minor: %f\n", det2);

    t_fl from_minor = minor(NULL, m3, (int []){1, 0}, 3);
    printf("Determinant with minor: %f\n", from_minor);


    
    return (0);
}