/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:55:48 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 14:05:03 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

int	color_print(t_trio src)
{
	int	i;

	if (!src)
		return (ft_error(EINVAL, "color_print"));
	if (printf("%15s", "color") < 0)
		return (ft_error(0, "printf"));
	i = 0;
	while (i < 3)
	{
		if (printf("\t") < 0)
			return (ft_error(0, "printf"));
		if (float_print(src[i]) != SUCCESS)
			return (ERROR);
		i++;
	}
	if (printf("\n") < 0)
		return (ft_error(0, "printf"));
	return (SUCCESS);
}

int	tuple_print(t_tuple src)
{
	int	i;

	if (!src)
		return (ft_error(EINVAL, "tuple_print"));
	if (src[W] == POINT)
		if (printf("%15s", "point") < 0)
			return (ft_error(0, "printf"));
	if (src[W] == VECTOR)
		if (printf("%15s", "vector") < 0)
			return (ft_error(0, "printf"));
	i = 0;
	while (i < 3)
	{
		if (printf("\t") < 0)
			return (ft_error(0, "printf"));
		if (float_print(src[i]) != SUCCESS)
			return (ERROR);
		i++;
	}
	if (printf("\n") < 0)
		return (ft_error(0, "printf"));
	return (SUCCESS);
}

int	matrix_print(t_matrix src)
{
	int	i;
	int	j;

	if (!src)
		return (ft_error(EINVAL, "matrix_print"));
	if (printf("%15s", "matrix") < 0)
		return (ft_error(0, "printf"));
	i = 0;
	while (i < 4)
	{
		if (i > 0 && printf("\t") < 0)
				return (ft_error(0, "printf"));
		j = 0;
		while (j < 4)
		{
			if (printf("\t") < 0)
				return (ft_error(0, "printf"));
			if (float_print(src[i][j++]) != SUCCESS)
				return (ERROR);
		}
		if (printf("\n") < 0)
			return (ft_error(0, "printf"));
		i++;
	}
	return (SUCCESS);
}
