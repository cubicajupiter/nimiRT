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

int	tuple_print(t_tuple src)
{
	if (!src)
		return (ft_error(EINVAL, "tuple_print"));
	if (src[W] == POINT)
		if (printf("p(%f, %f, %f)", src[X], src[Y], src[Z]) < 0)
			return (ft_error(0, "printf"));
	if (src[W] == VECTOR)
		if (printf("v(%f, %f, %f)", src[X], src[Y], src[Z]) < 0)
			return (ft_error(0, "printf"));
	return (SUCCESS);
}
