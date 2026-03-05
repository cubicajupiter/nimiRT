/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_ray_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 10:38:11 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/05 11:18:48 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	Get the point on the viewport of the camera that we are looking at. Z axis
	of the viewport is set at -1 as we are always looking in the same direction
	and the world moves around us.
*/
static inline void	camera_viewport_point_get(t_tuple viewport_point, 
					t_camera *camera, int x, int y)
{
	t_fl		xoffset;
	t_fl		yoffset;
	t_fl		xscene;
	t_fl		yscene;

	xoffset = ((t_fl)x + 0.5) * camera->pixel_size;
	yoffset = ((t_fl)y + 0.5) * camera->pixel_size;
	xscene = camera->half_width - xoffset;
	yscene = camera->half_height - yoffset;
	point_new(viewport_point, xscene, yscene, -1.0f);
}

/*
	pixel_ray_get()
	Gets a new ray for every window pixel. The new ray has an origin on camera
	viewport "surface" and a vector continuing on the same line from the
	original camera origin onwards into the scene.
*/
int	pixel_ray_get(t_ray pixel_ray, t_camera *camera, int x, int y)
{
	t_tuple		viewport_point;
	t_matrix	inverse_view_transform;

	if (!pixel_ray || !camera)
		return (ft_error(EINVAL, "pixel_ray_get"));
	camera_viewport_point_get(viewport_point, camera, x, y);
	matrix_invert(inverse_view_transform, camera->orientation);
	matrix_tuple_multiply_apply(viewport_point, inverse_view_transform);
	point_new(pixel_ray[ORIGIN], 0.0, 0.0, 0.0);
	matrix_tuple_multiply_apply(pixel_ray[ORIGIN], inverse_view_transform);
	tuple_minus_get(pixel_ray[DIRECTION], viewport_point, pixel_ray[ORIGIN]);
	normalize_apply(pixel_ray[DIRECTION]);
	return (SUCCESS);
}
