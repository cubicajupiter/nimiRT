/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrices.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:35:08 by jvalkama          #+#    #+#             */
/*   Updated: 2026/03/06 11:49:24 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	submatrix3(t_matrix3 dst, t_matrix src, int row, int column)
{
	size_t	i;
	size_t	j;
	size_t	r;
	size_t	c;

	i = 0;
	r = 0;
	while (i < 4)
	{
		if ((int)i != row)
		{
			j = 0;
			c = 0;
			while (j < 4)
			{
				if ((int)j != column)
					dst[r][c++] = src[i][j];
				++j;
			}
			++r;
		}
		++i;
	}
}

void	submatrix2(t_matrix2 dst, t_matrix3 src, int row, int column)
{
	size_t	i;
	size_t	j;
	size_t	r;
	size_t	c;

	i = 0;
	r = 0;
	while (i < 3)
	{
		if ((int)i != row)
		{
			j = 0;
			c = 0;
			while (j < 3)
			{
				if ((int)j != column)
					dst[r][c++] = src[i][j];
				++j;
			}
			++r;
		}
		++i;
	}
}
