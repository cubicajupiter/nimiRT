/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:50:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/05 17:12:18 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

int	translation(t_matrix dst, t_fl x, t_fl y, t_fl z)
{
	if (!dst)
		return (ft_error(EINVAL, "translation"));
	id_matrix(dst);
	dst[0][3] = x;
	dst[1][3] = y;
	dst[2][3] = z;
	return (SUCCESS);
}

int	scaling(t_matrix dst, t_fl x, t_fl y, t_fl z)
{
	if (!dst)
		return (ft_error(EINVAL, "scaling"));
	id_matrix(dst);
	dst[0][0] = x;
	dst[1][1] = y;
	dst[2][2] = z;
	return (SUCCESS);
}

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

int	shearing(t_matrix dst, t_fl src[6])
{
	if (!dst || !src)
		return (ft_error(EINVAL, "shearing"));
	id_matrix(dst);
	dst[0][1] = src[0];
	dst[0][2] = src[1];
	dst[1][0] = src[2];
	dst[1][2] = src[3];
	dst[2][0] = src[4];
	dst[2][1] = src[5];
	return (SUCCESS);
}
