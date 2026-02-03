/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trio_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:58:23 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/02 14:23:21 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int trio_add_get(t_trio dst, t_trio a, t_trio b)
{
	if (!dst || !a || !b)
		return (ft_error(EINVAL, "trio_add_get"));
	dst[0] = a[0] + b[0];
	dst[1] = a[1] + b[1];
	dst[2] = a[2] + b[2];
	return (SUCCESS);
}

int trio_add_apply(t_trio dst, t_trio c)
{
	if (!dst || !c)
		return (ft_error(EINVAL, "trio_add_apply"));
	dst[0] += c[0];
	dst[1] += c[1];
	dst[2] += c[2];
	return (SUCCESS);
}

int trio_minus_get(t_trio dst, t_trio a, t_trio b)
{
	if (!dst || !a || !b)
		return (ft_error(EINVAL, "trio_minus_get"));
	dst[0] = a[0] - b[0];
	dst[1] = a[1] - b[1];
	dst[2] = a[2] - b[2];
	return (SUCCESS);
}

int trio_minus_apply(t_trio dst, t_trio c)
{
	if (!dst || !c)
		return (ft_error(EINVAL, "trio_minus_apply"));
	dst[0] -= c[0];
	dst[1] -= c[1];
	dst[2] -= c[2];
	return (SUCCESS);
}
