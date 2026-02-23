/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_shade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:44:31 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/23 13:59:54 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

int	hit_shade(t_xs *hit, t_ray ray, t_scene *scene)
{
	if (!hit || !ray || !scene)
		return (ft_error(EINVAL, "hit_shade"));
	intersection_compute(hit, ray);
	if (is_shadowed(hit, scene) == FALSE)
		lighting(hit, &scene->light);
	// TODO: Maybe have a separate function wrapper for the trio_multiply_scalar_get
	// to make this bit of code more readible
	else
		trio_multiply_scalar_get(hit->object->material.shader.combined,
						   AMBIENT_RATIO,
						   hit->object->material.shader.ambi_refl);
	return (SUCCESS);
}
