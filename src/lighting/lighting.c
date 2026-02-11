/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:21:41 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/11 16:56:09 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "lighting.h"

/*
	Parameters:
	the material, 
	the point being illuminated, 
	the light source,
	the eye and normal vectors from the Phong reflection model
*/
int	lighting(t_object *obj, t_tuple point, t_light *l, t_tuple *vectors)
{
	t_trio		effective_color;
	t_tuple		light_vec;
	t_trio		ambient;
	t_trio		diffuse;
	t_trio		specular;
	t_fl		light_dot_normal;
	t_tuple		reflect_vec;
	t_tuple		neg_light_vec;
	t_fl		reflect_dot_eye;

	trio_multiply_get(effective_color, obj->material->color, l->intensity);
	tuple_minus_get(light_vec, l->pos, point);
	normalize_apply(light_vec);
	trio_multiply_scalar_get(ambient, obj->material->ambient, effective_color);
	vector_dot(&light_dot_normal, light_vec, vectors[NORMAL]);
	if (light_dot_normal < 0)
	{
		color_new(diffuse, 0, 0, 0);
		color_new(specular, 0, 0, 0);
	}
	else
	{
		trio_multiply_scalar_get(diffuse, light_dot_normal * obj->material->diffuse, effective_color);
		vector_negate(neg_light_vec, light_vec);
		reflection(reflect_vec, neg_light_vec, vectors[NORMAL]);
		vector_dot(&reflect_dot_eye, reflect_vec, vectors[EYE]);
		if (reflect_dot_eye <= 0)
			color_new(specular, 0, 0, 0);
		else
		{
			trio_multiply_scalar_get(specular, obj->material->specular * pow(reflect_dot_eye, obj->material->shininess), l->intensity);
		}
	}
	obj->shading;
}