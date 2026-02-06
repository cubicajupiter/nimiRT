/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:19:34 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/05 16:23:17 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Degrees to radian converter
*/

int	ft_dtor(float *dst, int src)
{
	if (!dst)
		return (ft_error(EINVAL, "ft_dtor"));
	*dst = src / 180.0 * PI;
	return (SUCCESS);
}
