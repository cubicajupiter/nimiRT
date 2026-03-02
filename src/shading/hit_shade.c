/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_shade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:44:31 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/01 10:41:42 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

static void	shadow(t_xs *hit);
static int	intersection_compute(t_xs *hit, t_ray ray);

int	hit_shade(t_xs *hit, t_ray ray, t_scene *scene)
{
	if (!hit || !ray || !scene)
		return (ft_error(EINVAL, "hit_shade"));
	intersection_compute(hit, ray);
	if (is_shadowed(hit, scene) == FALSE)
		lighting(hit, &scene->light);
	else
		shadow(hit);
	return (SUCCESS);
}

/*
	intersection_compute()
	Computes data about an intersection point on a object including the position
	the vector back to the camera, the vector of the normal at that point on the
	object and whether the camera is inside the object or not.
*/
static int	intersection_compute(t_xs *hit, t_ray ray)
{
	t_fl	dot;

	if (!hit || !ray)
		return (ft_error(EINVAL, "intersection_compute"));
	if (position_get(hit->point, ray, hit->t) != SUCCESS
		|| vector_negate(hit->camera_vector, ray[DIRECTION]) != SUCCESS
		|| normal_get(hit->normal_vector,
			hit->object, hit->point) != SUCCESS
		|| vector_dot(&dot, hit->normal_vector, hit->camera_vector) != SUCCESS)
		return (ft_error(EINHERIT, "intersection_compute"));
	if (dot < 0)
	{
		hit->inside = true;
		if (vector_negate(hit->normal_vector, hit->normal_vector) != SUCCESS)
			return (ft_error(EINHERIT, "intersection_compute"));
	}
	else
		hit->inside = false;
	return (SUCCESS);
}

static void	shadow(t_xs *hit)
{
	trio_multiply_scalar_get(hit->object->material.shader.combined,
		AMBIENT_RATIO, hit->object->material.shader.ambi_refl);
}
