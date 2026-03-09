/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_and_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:49:39 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/09 17:26:31 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "miniRT.h"

int	window_init(mlx_t **window, mlx_image_t **image)
{
	*window = mlx_init(WIDTH, HEIGHT, "miniRT", FALSE);
	if (!window || !*window)
		ft_error(EFAULT, mlx_strerror(mlx_get_errno()));
	else
		errno = 0;
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
	mlx_terminate(window);
	return (SUCCESS);
}

void	commands(void *data)
{
	t_tree	*t;

	t = (t_tree *)data;
	if (mlx_is_key_down(t->window, MLX_KEY_ESCAPE))
	{
		mlx_delete_image(t->window, t->image);
		mlx_close_window(t->window);
		t->image = NULL;
		errno = 0;
	}
}
