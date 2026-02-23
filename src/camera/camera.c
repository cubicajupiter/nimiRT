/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:28:21 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/23 13:58:48 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	camera_compute(t_camera *camera)
{
	t_tuple	up_v;

	if (!camera)
		return (ft_error(EINVAL, "camera_compute"));
	vector_new(up_v, 0.0, 1.0, 0.0);
	view_transform_get(camera->orientation, camera->ray[ORIGIN],
		camera->ray[DIRECTION], up_v);
	camera_pixel_size_compute(camera);
	return (SUCCESS);
}

int	camera_pixel_size_compute(t_camera *camera)
{
	t_fl	half_view;
	t_fl	aspect_ratio;

	if (!camera)
		return (ft_error(EINVAL, "camera_set"));
	half_view = ft_tan(camera->fov / 2.0);
	aspect_ratio = (t_fl)WIDTH / (t_fl)HEIGHT;
	if (aspect_ratio >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect_ratio;
	}
	else
	{
		camera->half_width = half_view * aspect_ratio;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / WIDTH;
	return (SUCCESS);
}

/*
	Get the point on the viewport of the camera that we are looking at. Z axis
	of the viewport is set at -1 as we are always looking in the same direction
	and the world moves around us.
*/
static void	camera_viewport_point_get(t_tuple viewport_point, t_camera *camera,
				int x, int y)
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
