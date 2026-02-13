/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_sources.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:31:03 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/13 11:19:13 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	point_light_new(t_light *dst, t_tuple position, t_trio intensity)
{
	tuple_copy(dst->point, position);
	color_copy(dst->brightness, intensity);
}