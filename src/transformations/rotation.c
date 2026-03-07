/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:50:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/05 12:19:13 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

/* Rotation_x: rotation clockwise in the x dimension (e.g. merry-go-round) 
	AROUND THE X AXIS. So X dimension of the normal vector does not change.
	Normal vector's Y and Z balance shifts.
*/
int	rotation_x(t_matrix dst, t_fl radians)
{
	if (!dst)
		return (ft_error(EINVAL, "rotation_x"));
	id_matrix(dst);
	dst[1][1] = ft_cos((double)radians);
	dst[1][2] = -ft_sin((double)radians);
	dst[2][1] = ft_sin((double)radians);
	dst[2][2] = ft_cos((double)radians);
	return (SUCCESS);
}

/* Rotation_y: rotation clockwise in the y dimension (e.g. clockface) 
	AROUND THE Y AXIS. So Y dimension of the normal vector does not change.
	Normal vector's Z and X balance shifts.
*/
int	rotation_y(t_matrix dst, t_fl radians)
{
	if (!dst)
		return (ft_error(EINVAL, "rotation_y"));
	id_matrix(dst);
	dst[0][0] = ft_cos((double)radians);
	dst[2][0] = -ft_sin((double)radians);
	dst[0][2] = ft_sin((double)radians);
	dst[2][2] = ft_cos((double)radians);
	return (SUCCESS);
}

/* Rotation_z: rotation clockwise in the z dimension (e.g. bikewheels beneath
 * you as the rider) 
	AROUND THE Z AXIS. So Z dimension of the normal vector does not change.
	Normal vector's X and Y balance shifts.
 */
int	rotation_z(t_matrix dst, t_fl radians)
{
	if (!dst)
		return (ft_error(EINVAL, "rotation_z"));
	id_matrix(dst);
	dst[0][0] = ft_cos((double)radians);
	dst[0][1] = -ft_sin((double)radians);
	dst[1][0] = ft_sin((double)radians);
	dst[1][1] = ft_cos((double)radians);
	return (SUCCESS);
}

int	rotation_full3d(t_matrix dst, t_tuple normal)
{
	t_fl		dp_x;
	t_fl		dp_y;
	t_fl		dp_z;
	t_matrix	z_rotate_transform;
	t_matrix	x_rotate_transform;
	t_matrix	y_rotate_transform;

	if (!dst || !normal)
		return (ft_error(EINVAL, "rotation_full3D"));
	vector_dot_selective(&dp_x, normal, (t_tuple){0, 1, 0, 0}, X); //performance impact of declaring compound literals three times shouldn't be too huge since this is only done at initialisation.
	vector_dot_selective(&dp_y, normal, (t_tuple){0, 1, 0, 0}, Y);
	vector_dot_selective(&dp_z, normal, (t_tuple){0, 1, 0, 0}, Z);
	rotation_x(x_rotate_transform, acos(dp_x));
	rotation_z(z_rotate_transform, acos(dp_z));
	rotation_y(y_rotate_transform, acos(dp_y));
	//chain3_apply(dst, x_rotate_transform, z_rotate_transform); //TODO: more testing of different dimensions' effect on rotation
	chain4_apply(dst, x_rotate_transform, z_rotate_transform, y_rotate_transform);
	return (SUCCESS);
}

/* Rotation_xz: rotation clockwise in the x di mension (e.g. merry-go-round)
 * and rotation clockwise in the z dimension (e.g. bikewheels beneath
 * you as the rider) 
	This function is useful for rotating cylinders and planes as we only need
	rotation in 2 dimensions (both objects have symmetry around Y axis)
	The float value for roll required flipping (negative<>positive) after
	testing.
 */
int	rotation_xz(t_matrix dst, t_tuple normal)
{
	t_matrix	x_rotate_trans;
	t_matrix	z_rotate_trans;
	t_fl		pitch;
	t_fl		roll;

	if (!dst || !normal)
		return (ft_error(EINVAL, "rotation_xz"));
	if (is_float_equal(normal[Y], EPSILON)
		&& is_float_equal(normal[Z], EPSILON))
		pitch = 0.0f;
	else
		pitch = atanf(normal[Z] / normal[Y]);
	if (is_float_equal(normal[Y], EPSILON)
		&& is_float_equal(normal[X], EPSILON))
		roll = 0.0f;
	else
		roll = -atanf(normal[X] / normal[Y]);
	rotation_x(x_rotate_trans, pitch);
	rotation_z(z_rotate_trans, roll);
	chain3_apply(dst, z_rotate_trans, x_rotate_trans);
	return (SUCCESS);
}
