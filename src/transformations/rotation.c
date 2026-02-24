/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:50:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/06 11:37:14 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

/* Rotation_x: rotation clockwise in the x dimension (e.g. merry-go-round) 
	AROUND THE X AXIS. So X dimension of the normal vector does not change. Normal vector's Y and Z balance shifts.
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
	AROUND THE Y AXIS. So Y dimension of the normal vector does not change. Normal vector's Z and X balance shifts.
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
	AROUND THE Z AXIS. So Z dimension of the normal vector does not change. Normal vector's X and Y balance shifts.
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

int	rotation_full3D(t_matrix dst, t_tuple normal)
{
	t_matrix	y_rotate_trans;
	t_matrix	x_rotate_trans;
	t_fl		yaw;
	t_fl		pitch;

	if (!dst || !normal)
		return (ft_error(EINVAL, "rotation_full3D"));
	yaw = (t_fl) atan2((double)normal[X], (double)normal[Z]);
	pitch = (t_fl) acos((double) normal[Y]);
	rotation_y(y_rotate_trans, yaw);
	rotation_x(x_rotate_trans, pitch);
	chain3_apply(dst, y_rotate_trans, x_rotate_trans);
	return (SUCCESS);
}