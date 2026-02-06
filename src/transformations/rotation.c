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

/* Rotation_x: rotation clockwise in the x dimension (e.g. merry-go-round) */
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

/* Rotation_y: rotation clockwise in the y dimension (e.g. clockface) */
int	rotation_y(t_matrix dst, t_fl radians)
{
	if (!dst)
		return (ft_error(EINVAL, "rotation_x"));
	id_matrix(dst);
	dst[0][0] = ft_cos((double)radians);
	dst[2][0] = -ft_sin((double)radians);
	dst[0][2] = ft_sin((double)radians);
	dst[2][2] = ft_cos((double)radians);
	return (SUCCESS);
}

/* Rotation_z: rotation clockwise in the z dimension (e.g. bikewheels beneath
 * you as the rider) */
int	rotation_z(t_matrix dst, t_fl radians)
{
	if (!dst)
		return (ft_error(EINVAL, "rotation_x"));
	id_matrix(dst);
	dst[0][0] = ft_cos((double)radians);
	dst[0][1] = -ft_sin((double)radians);
	dst[1][0] = ft_sin((double)radians);
	dst[1][1] = ft_cos((double)radians);
	return (SUCCESS);
}
