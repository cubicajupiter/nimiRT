/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:34:03 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/02 15:37:44 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	canvas_put(mlx_image_t *image, t_trio color)
{
	t_uint	x;
	t_uint	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (pixel_put(image, x, y, color) != SUCCESS)
				return (ERROR);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
