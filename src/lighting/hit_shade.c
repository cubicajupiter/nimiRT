/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_shade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:44:31 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/23 17:09:06 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

static void	shadow(t_xs *hit);

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
		shadow(hit);
	return (SUCCESS);
}

static void	shadow(t_xs *hit)
{
	trio_multiply_scalar_get(hit->object->material.shader.combined,
							AMBIENT_RATIO,
							hit->object->material.shader.ambi_refl);
}
