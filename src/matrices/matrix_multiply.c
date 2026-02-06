/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:23:56 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/06 12:04:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	matrix_multiply_get(t_matrix dst, t_matrix a, t_matrix b)
{
	t_fl	result;
	int		i;
	int		j;

	if (!dst || !a || !b)
		return (ft_error(EINVAL, "matrix_multiply"));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result = 0.0;
			result += a[i][0] * b[0][j];
			result += a[i][1] * b[1][j];
			result += a[i][2] * b[2][j];
			result += a[i][3] * b[3][j];
			dst[i][j] = result;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	matrix_tuple_multiply_get(t_tuple dst, t_matrix a, t_tuple b)
{
	t_fl	result;
	int		i;
	int		j;

	if (!dst || !a || !b)
		return (ft_error(EINVAL, "matrix_tuple_multiply"));
	i = 0;
	while (i < 4)
	{
		j = 0;
		result = 0.0f;
		while (j < 4)
		{
			result += a[i][j] * b[j];
			j++;
		}
		dst[i] = result;
		i++;
	}
	return (SUCCESS);
}

int	matrix_multiply_apply(t_matrix dst, t_matrix a)
{
	t_matrix	b;
	t_fl		result;
	int			i;
	int			j;

	if (!dst || !a)
		return (ft_error(EINVAL, "matrix_multiply"));
	matrix_copy(b, dst);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result = 0.0;
			result += a[i][0] * b[0][j];
			result += a[i][1] * b[1][j];
			result += a[i][2] * b[2][j];
			result += a[i][3] * b[3][j];
			dst[i][j] = result;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	matrix_tuple_multiply_apply(t_tuple dst, t_matrix a)
{
	t_tuple	b;
	t_fl	result;
	int		i;
	int		j;

	if (!dst || !a)
		return (ft_error(EINVAL, "matrix_tuple_multiply"));
	tuple_copy(b, dst);
	i = 0;
	while (i < 4)
	{
		j = 0;
		result = 0.0f;
		while (j < 4)
		{
			result += a[i][j] * b[j];
			j++;
		}
		dst[i] = result;
		i++;
	}
	return (SUCCESS);
}
