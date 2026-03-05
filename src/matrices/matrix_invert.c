/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:20:21 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/23 14:22:09 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_invert.h"
#include "miniRT.h"

static t_fl			minor(t_matrix matrix4, t_matrix3 matrix3, int coord[2], int size);

int	matrix_invert(t_matrix dst, t_matrix src)
{
	t_fl	det;
	t_fl	cof;
	size_t	i;
	size_t	j;

	if (!dst || !src)
		return (ft_error(EINVAL, "matrix_invert"));
	if (!is_invertible(src))
		return (1);
	i = 0;
	j = 0;
	determinant(&det, NULL, src, 4);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			cof = cofactor(src, NULL, (int []){i, j}, 4);
			dst[j][i] = cof / det;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static t_fl	minor(t_matrix matrix4, t_matrix3 matrix3, int coord[2], int size)
{
	t_fl		det;
	t_matrix2	tmp2x2;
	t_matrix3	tmp3x3;

	det = 0.0;
	if (size == 3)
	{
		submatrix2(tmp2x2, matrix3, coord[ROW], coord[COLUMN]);
		determinant2(&det, tmp2x2);
	}
	else if (size == 4)
	{
		submatrix3(tmp3x3, matrix4, coord[ROW], coord[COLUMN]);
		determinant(&det, tmp3x3, NULL, 3);
	}
	return (det);
}

t_fl	cofactor(t_matrix matrix4, t_matrix3 matrix3, int coord[2], int size)
{
	t_fl	det;

	det = 0.0;
	if (size == 4)
		det = minor(matrix4, NULL, coord, size);
	if (size == 3)
		det = minor(NULL, matrix3, coord, size);
	if ((coord[ROW] + coord[COLUMN]) % 2 == 1)
		det *= -1;
	return (det);
}

inline bool	is_invertible(t_matrix matrix4)
{
	t_fl	det;

	if (!matrix4)
		return (false);
	determinant(&det, NULL, matrix4, 4);
	if (is_float_equal(det, 0.0))
		return (false);
	return (true);
}
