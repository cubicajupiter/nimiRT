/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:20:21 by jvalkama          #+#    #+#             */
/*   Updated: 2026/03/09 18:14:19 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_invert.h"
#include "miniRT.h"

int	matrix_invert(t_matrix dst, t_matrix src)
{
	t_fl	determinant;
	t_fl	cofactor;
	size_t	i;
	size_t	j;

	if (!dst || !src)
		return (ft_error(EINVAL, "matrix_invert"));
	determinant4(&determinant, src);
	if (!is_invertible(&determinant))
		return (FAIL);
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			cofactor4(&cofactor, src, (int []){i, j});
			dst[j][i] = cofactor / determinant;
			++j;
		}
		++i;
	}
	return (SUCCESS);
}

void	cofactor3(t_fl *dst, t_matrix3 matrix3, int coord[2])
{
	minor_determinant3(dst, matrix3, coord);
	if ((coord[ROW] + coord[COLUMN]) % 2 == 1)
		*dst *= -1;
}

void	cofactor4(t_fl *dst, t_matrix matrix4, int coord[2])
{
	minor_determinant4(dst, matrix4, coord);
	if ((coord[ROW] + coord[COLUMN]) % 2 == 1)
		*dst *= -1;
}

bool	is_invertible(t_fl *determinant)
{
	if (is_float_equal(*determinant, 0.0))
		return (false);
	return (true);
}
