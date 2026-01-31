/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:55:48 by thblack-          #+#    #+#             */
/*   Updated: 2026/01/30 18:03:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

int	tuple_print(tuple src)
{
	if (!src)
		return (ERROR);
	if (src[W] == POINT)
		if (printf("p(%f, %f, %f)\n", src[X], src[Y], src[Z]))
			return (ERROR);
	if (src[W] == VECTOR)
		if (printf("v(%f, %f, %f)\n", src[X], src[Y], src[Z]))
			return (ERROR);
	return (SUCCESS);
}
