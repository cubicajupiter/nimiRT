/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:56:20 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/04 17:14:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	matrix_copy(t_matrix dst, t_matrix src)
{
	int	i;
	int	j;

	if (!dst || ! src)
		return (ft_error(EINVAL, "matrix_new"));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	id_matrix(t_matrix dst)
{
	int	i;
	int	j;

	if (!dst)
		return (ft_error(EINVAL, "matrix_id_get"));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				dst[i][j] = 1.0f;
			else
				dst[i][j] = 0.0f;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
