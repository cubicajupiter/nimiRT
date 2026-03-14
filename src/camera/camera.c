/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:28:21 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/09 17:50:52 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	pointing_up_or_down(t_tuple camera_ray);
static int	camera_pixel_size_compute(t_camera *camera);

// camera_compute()
// Calculates the camera for usage in the main render loop. Only happens once
// before the image pixel loop. A matrix transform is calculated (we start with
// the assumption the camera is pointing forward in the Z direction, then apply
// transformations from there), then the camera viewport is calculated in
// relation to the field-of-view (fov) and the window size (defined as WIDTH and
// HEIGHT respectively in the defines.h header.
int	camera_compute(t_camera *camera)
{
	t_tuple	up_v;

	if (!camera)
		return (ft_error(EINVAL, "camera_compute"));
	if (pointing_up_or_down(camera->ray[DIRECTION]))
		vector_new(up_v, 0.0, 0.0, 1.0);
	else
		vector_new(up_v, 0.0, 1.0, 0.0);
	view_transform_get(camera->orientation, camera->ray[ORIGIN],
		camera->ray[DIRECTION], up_v);
	camera_pixel_size_compute(camera);
	return (SUCCESS);
}

static int	pointing_up_or_down(t_tuple camera_ray)
{
	if (!camera_ray)
		return (ft_error(EINVAL, "camera_ray"));
	if (is_float_equal(camera_ray[X], EPSILON)
		&& is_float_equal(camera_ray[Z], EPSILON)
		&& !is_float_equal(camera_ray[Y], 0.0))
		return (TRUE);
	return (FALSE);
}

static int	camera_pixel_size_compute(t_camera *camera)
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
