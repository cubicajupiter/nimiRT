/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:18:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/20 15:52:11 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//specular_refl and diffuse_refl in material.shader can be initialised to just zero, and ambient_refl to 0.1
//so if the hit is in shadow, pixel color is already set by default.

// passing as parameter a pointer to t_scene is likely more optimized than making a local copy of that entire struct
int	is_shadowed(t_scene *scene, t_tuple hit_p)
{
	t_fl		distance;
	t_tuple		direction_v;
	t_tuple		light_ray_v;

	if (!scene || !hit_p)
		return (ft_error(EINVAL, "is_shadowed"));
	tuple_minus_get(direction_v, scene->light.point, hit_p);
	magnitude_get(&distance, direction_v);
	normalize_apply(direction_v);
	ray_new(&light_ray_v, hit_p, direction_v);
	if (is_shadow_hit(light_ray_v, scene, distance))
	{
		tuple_copy(scene->xs->light_vector, light_ray_v);
		return (TRUE);
	}
	return (FALSE);
}

int	overpoint_get(t_xs *hit)
{
	t_tuple		offset_v;

	if (!hit)
		return (ft_error(EINVAL, "overpoint_get"));
	vector_multiply_get(offset_v, EPSILON, hit->normal_vector);
	tuple_add_get(hit->over_point, hit->point, offset_v);
}

//the following additions are made to hit_shade once it's done.
// void hit_shade(void) 
// {
 	// add over_point in xs.
// 	overpoint_get(&hit);

// 	is_shadowed(scene, hit.over_point); //is_shadowed has to be called with the new over-point.

// 	lighting(); //called with overpoint also. Or perhaps this change is better made inside lighting().
// }
