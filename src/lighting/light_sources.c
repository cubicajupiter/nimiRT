/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_sources.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:31:03 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/13 17:40:46 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	point_light_new(t_light *dst, t_tuple position, t_trio intensity)
{
	if (!dst || !position || !intensity)
		return (ft_error(EINVAL, "point_light_new"));
	tuple_copy(dst->point, position);
	color_copy(dst->color, intensity);
	return (SUCCESS);
}
