/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:11:05 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/09 17:50:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

static inline bool	is_pixel_on_image(t_uint x, t_uint y)
{
	if (x < WIDTH && y < HEIGHT)
		return (true);
	return (false);
}

int	pixel_put(mlx_image_t *image, t_uint x, t_uint y, t_trio c)
{
	uint32_t	color;

	if (!image || !c)
		return (ft_error(EINVAL, "pixel_put"));
	if (is_pixel_on_image(x, y))
	{
		color_trio_to_uint(&color, c);
		mlx_put_pixel(image, x, y, color);
	}
	return (SUCCESS);
}
