/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:53:19 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/23 14:21:10 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	matrix_compare(t_matrix a, t_matrix b)
{
	size_t	i;
	size_t	j;

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
	size_t	i;
	size_t	j;

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
