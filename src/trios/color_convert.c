/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:21:13 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/02 14:33:42 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdint.h>

static uint8_t	color_float_to_8bit(float c)
{
	return ((uint8_t)c * 255);
}

int	color_trio_to_uint(uint32_t *color, t_trio c)
{
	if (!c)
		return (ft_error(EINVAL, "color_trio_to_uint"));
	*color = 0;
	*color = color_float_to_8bit(c[R]) << 24
		| color_float_to_8bit(c[G]) << 16
		| color_float_to_8bit(c[B]) << 8
		| ALPHA;
	return (SUCCESS);
}
