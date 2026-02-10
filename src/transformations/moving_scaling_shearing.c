/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_scaling_shearing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:36:21 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/10 09:26:49 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Translation: essentially moving objects */
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

/* Scaling: making objects bigger or smaller */
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

/* Shearing: changing the shape of an object by shearing (e.g. gradually
 * pushing over a jenga tower). Input is expected as a float[6] array with
 * the shear values XY, XZ, YX, YZ, ZX, ZY. The first value of each pair is
 * the value that will be changed, the second value of each pair is the value
 * it scales against. E.g. if X is 2 and Y is 3 then the matrix will apply
 * a 6 fold increase in the X dimension to the point or vector the matrix is
 * applied to. */
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
