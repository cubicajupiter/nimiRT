/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:28:18 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/10 14:18:09 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	normal_sphere_get(t_tuple dst, t_sphere *sphere, t_tuple point)
{
	tuple_minus_get(dst, point, sphere->center);
	normalize_apply(dst);
	return (SUCCESS);
}
