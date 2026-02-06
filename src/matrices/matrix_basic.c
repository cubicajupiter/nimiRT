/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:53:19 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/06 14:37:09 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	matrix_compare(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	if (!a || !b)
		return (ft_error(EINVAL, "matrix_compare"));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (is_float_equal(a[i][j], b[i][j]) == false)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	matrix_transpose(t_matrix dst, t_matrix src)
{
	int	i;
	int	j;

	if (!dst || !src)
		return (ft_error(EINVAL, "matrix_transpose"));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dst[j][i] = src[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

/*
	Gets you the Identity Matrix (builds it and places it).
	When any matrix is multiplied by the identity matrix, the result is the
	matrix itself.
	Multiplying the identity matrix by any tuple keeps the identity matrix
	unchanged. Used for default transformations.
*/
int	matrix_identity_get(t_matrix identity)
{
	int	i;
	int	j;
	int	count;

	if (!identity)
		return (ft_error(EINVAL, "matrix_identity_get"));
	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (count % 5 == 0)
				identity[i][j] = 1;
			else
				identity[i][j] = 0;
			j++;
			count++;
		}
		i++;
	}
	return (SUCCESS);
}
