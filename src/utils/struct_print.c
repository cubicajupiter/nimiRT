/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:55:48 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/02 14:25:36 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

/*
 * float_print() aligns numbers regardless of sign (minus or positive)
*/

static int	float_print(t_fl fl)
{
	if (fl < 0)
	{
		if (printf("%f", fl) < 0)
			return (ft_error(0, "printf"));
	}
	else
		if (printf(" %f", fl) < 0)
			return (ft_error(0, "printf"));
	return (SUCCESS);
}

int	tuple_print(t_tuple src)
{
	int	i;

	if (!src)
		return (ft_error(EINVAL, "tuple_print"));
	if (src[W] == POINT)
		if (printf("point") < 0)
			return (ft_error(0, "printf"));
	if (src[W] == VECTOR)
		if (printf("vector") < 0)
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
	if (printf("matrix") < 0)
		return (ft_error(0, "printf"));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (printf("\t") < 0)
				return (ft_error(0, "printf"));
			if (float_print(src[i][j]) != SUCCESS)
				return (ERROR);
			j++;
		}
		if (printf("\n") < 0)
			return (ft_error(0, "printf"));
		i++;
	}
	return (SUCCESS);
}
