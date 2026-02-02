/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:49:39 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/02 11:50:17 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "miniRT.h"

int	window_init(mlx_t **window, mlx_image_t **image)
{
	*window = mlx_init(WIDTH, HEIGHT, "Fract-ol", FALSE);
	if (!window || !*window)
		ft_error(EFAULT, mlx_strerror(mlx_get_errno()));
	*image = mlx_new_image(*window, WIDTH, HEIGHT);
	if (!*image)
		ft_error(EFAULT, mlx_strerror(mlx_get_errno()));
	if (mlx_image_to_window(*window, *image, 0, 0) < 0)
	{
		ft_error(EIO, mlx_strerror(mlx_get_errno()));
		mlx_close_window(*window);
	}
	return (SUCCESS);
}

int	window_destroy(mlx_t *window)
{
	mlx_close_window(window);
	mlx_terminate(window);
	return (SUCCESS);
}
