/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_submatrices.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:35:08 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/03 11:52:30 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	Divide-and-conquer.
	4x4 is broken down to 3x3, then 2x2
	--> 2x2 matrices needed to find the determinant(s) of a 4x4 matrix.
	Determinants are needed for inverting a 4x4 matrix.
*/

t_matrix3	submatrix3(t_matrix src, int row, int column)
{
	t_matrix3	new;
	int			i;
	int			j;

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
					**new = src[i][j];
					*new++;
				}
				j++;
			}
			new++;
		}
		i++;
	}
	return (new);
}

t_matrix2	submatrix2(t_matrix3 src, int row, int column)
{
	t_matrix2	new;
	int			i;
	int			j;

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
					**new = src[i][j];
					*new++;
				}
				j++;
			}
			new++;
		}
		i++;
	}
	return (new);
}
