/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trio_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:06:13 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/11 15:51:49 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	trio_divide_get(t_trio dst, t_trio a, t_trio b)
{
	if (!dst || !a || !b)
		return (ft_error(EINVAL, "trio_divide_get"));
	dst[0] = a[0] / b[0];
	dst[1] = a[1] / b[1];
	dst[2] = a[2] / b[2];
	return (SUCCESS);
}

int	trio_divide_apply(t_trio dst, t_trio c)
{
	if (!dst || !c)
		return (ft_error(EINVAL, "trio_divide_apply"));
	dst[0] /= c[0];
	dst[1] /= c[1];
	dst[2] /= c[2];
	return (SUCCESS);
}