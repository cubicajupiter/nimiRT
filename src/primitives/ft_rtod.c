/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:12:19 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/05 16:22:46 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Radian to degrees converter
*/

int	ft_rtod(int *dst, float src)
{
	long long	tmp;

	if (!dst)
		return (ft_error(EINVAL, "ft_rtod"));
	tmp = src / PI * 180;
	if (tmp > INT_MAX || tmp < INT_MIN)
		return (ft_error(EOVERFLOW, "ft_rtod"));
	*dst = (int)tmp;
	return (SUCCESS);
}
