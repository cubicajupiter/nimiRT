/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:35:08 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/02 19:13:48 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	Divide-and-conquer.
	4x4 is broken down to 3x3, then 2x2
	--> 2x2 matrices needed to find the determinant(s) of a 4x4 matrix.
	Determinants are needed for inverting a 4x4 matrix.
*/

int	submatrix3(matrix3 dst, matrix src, int row, int column)
{
	int		i;
	int		j;

	if (!dst || !src || !row || !column \
		|| row > 3 || row < 0 || column > 3 || column < 0)
		return (ft_error(EINVAL, "submatrix3"));
	i = 0;
	while (i < 4)
	{
		if (i != row)
		{
			j = 0;
			while (j < 4)
			{
				if (j != column)
				{
					**dst = src[i][j];
					*dst++;
				}
				j++;
			}
			dst++;
		}
		i++;
	}
}

int	submatrix2(matrix2 dst, matrix3 src, int row, int column)
{
	int		i;
	int		j;

	if (!dst || !src || !row || !column \
		|| row > 2 || row < 0 || column > 2 || column < 0)
		return (ft_error(EINVAL, "submatrix2"));
	i = 0;
	while (i < 3)
	{
		if (i != row)
		{
			j = 0;
			while (j < 3)
			{
				if (j != column)
				{
					**dst = src[i][j];
					*dst++;
				}
				j++;
			}
			dst++;
		}
		i++;
	}
}
