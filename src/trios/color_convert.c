/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:21:13 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/11 16:10:32 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdint.h>

static uint8_t	color_float_to_8bit(t_fl c)
{
	return ((uint8_t)c * 255);
}

static t_fl	color_8bit_to_float(int c)
{
	return ((t_fl)c / 255.0f);
}

int	color_trio_to_uint(uint32_t *color, t_trio c)
{
	if (!color || !c)
		return (ft_error(EINVAL, "color_trio_to_uint"));
	*color = 0;
	*color = color_float_to_8bit(c[R]) << 24
		| color_float_to_8bit(c[G]) << 16
		| color_float_to_8bit(c[B]) << 8
		| ALPHA;
	return (SUCCESS);
}

int	color_uint_to_trio(t_trio c, int *color)
{
	if (!c || !color)
		return (ft_error(EINVAL, "color_uint_to_trio"));
	if (color[R] < 0 || color[R] > 255
		|| color[G] < 0 || color[G] > 255
		|| color[B] < 0 || color[B] > 255)
		return (FAIL);
	c[R] = color_8bit_to_float(color[R]);
	c[G] = color_8bit_to_float(color[G]);
	c[B] = color_8bit_to_float(color[B]);
	return (SUCCESS);
}
