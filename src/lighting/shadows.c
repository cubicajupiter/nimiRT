/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:18:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/24 09:58:22 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_shadow_hit(t_xs *hit, t_fl distance,
			t_ray light_ray, t_vec *objects);

//specular_refl and diffuse_refl in material.shader can be initialised to just zero, and ambient_refl to 0.1
//so if the hit is in shadow, pixel color is already set by default.

// passing as parameter a pointer to t_scene is likely more optimized than making a local copy of that entire struct
int	is_shadowed(t_xs *hit, t_scene *scene)
{
	t_fl		distance;
	t_tuple		direction_v;
	t_ray		light_ray;

	if (!hit || !scene)
		return (ft_error(EINVAL, "is_shadowed"));
	tuple_minus_get(direction_v, scene->light.point, hit->point);
	magnitude_get(&distance, direction_v);
	normalize_apply(direction_v);
	if (hit->object->type == PLANE)
		ray_new(light_ray, hit->point, direction_v);
	else
	{
		overpoint_get(hit);
		ray_new(light_ray, hit->over_point, direction_v);
	}
	if (is_shadow_hit(hit, distance, light_ray, scene->objects))
		return (TRUE);
	tuple_copy(hit->light_vector, direction_v);
	return (FALSE);
}

// OPTIMISATION: overpoint no longer needed. now shadows are just never tested against the object itself.
int	overpoint_get(t_xs *hit)
{
	t_tuple		offset_v;

	if (!hit)
		return (ft_error(EINVAL, "overpoint_get"));
	vector_multiply_get(offset_v, EPSILON * 100.0, hit->normal_vector);
	tuple_add_get(hit->over_point, hit->point, offset_v);
	return (SUCCESS);
}

int	is_shadow_hit(t_xs *hit, t_fl distance, t_ray light_ray, t_vec *objects)
{
	t_object	*object;
	size_t		i;
	t_fl		t;

	if (!hit || !light_ray || !objects || distance < 0.0)
		return (ft_error(EINVAL, "is_shadow_hit"));
	t = -1.0;
	i = 0;
	while (i < objects->len)
	{
		object = vec_get(objects, i++);
		// if (hit->object->id == object->id)
		// {
		// 	if (hit->object->type != CYLINDER)
		// 		continue ;
		// 	else if (object_hit_get(&t, object, light_ray)
		// 	&& t > 0.0 && t < distance)
		// 		return (TRUE);
		// }
		if (object_hit_get(&t, object, light_ray)
			&& t > 0.0 && t < distance)
				return (TRUE);
	}
	return (FALSE);
}

//the following additions are made to hit_shade once it's done.
// void hit_shade(void) 
// {
 	// add over_point in xs.
// 	overpoint_get(&hit);

// 	is_shadowed(scene, hit.over_point); //is_shadowed has to be called with the new over-point.

// 	lighting(); //called with overpoint also. Or perhaps this change is better made inside lighting().
// }
