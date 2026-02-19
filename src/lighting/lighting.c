/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:21:41 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/18 15:20:31 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	light_vector_get(t_tuple dst, t_light *light, t_tuple point);
static t_fl	eye_vec_dot_product(t_tuple light_v, t_tuple neglight_v,
				t_tuple eye_vector, t_tuple normal_vector);
static void	reflections_combine(t_material *mat);

/*
	Parameters:
	- the hit (struct contains t distance, object, materials and vectors for
		camera, normal, and light)
	- the light source
*/
int	lighting(t_xs *hit, t_light *light)
{
	t_fl		light_dot;
	t_fl		eye_dot;
	t_tuple		light_v;
	t_tuple		neglight_v;

	if (!hit || !light)
		return (ft_error(EINVAL, "lighting"));
	light_vector_get(light_v, light, hit->point);
	vector_dot(&light_dot, light_v, hit->normal_vector);
	if (light_dot < 0)
		reflection_specular(&hit->object->material, NULL, 0.0);
	else
	{
		eye_dot = eye_vec_dot_product(light_v, neglight_v,
					hit->camera_vector, hit->normal_vector);
		if (eye_dot <= 0)
			reflection_specular(&hit->object->material, NULL, eye_dot);
		else
			reflection_specular(&hit->object->material, light, eye_dot);
	}
	reflection_diffuse(&hit->object->material, light_dot);
	reflections_combine(&hit->object->material);
	return (SUCCESS);
}

static void	light_vector_get(t_tuple dst, t_light *light, t_tuple point)
{
	tuple_minus_get(dst, light->point, point);
	normalize_apply(dst);
}

static t_fl	eye_vec_dot_product(t_tuple light_v, t_tuple neglight_v,
				t_tuple eye_vector, t_tuple normal_vector)
{
	t_fl		eye_dot_product;
	t_tuple		refl_v;

	vector_negate(neglight_v, light_v);
	reflection_get(refl_v, neglight_v, normal_vector);
	vector_dot(&eye_dot_product, refl_v, eye_vector);
	return (eye_dot_product);
}

static void	reflections_combine(t_material *mat)
{
	t_trio	ambient_tmp;
	t_trio	diffuse_tmp;
	t_trio	specular_tmp;
	// t_fl	scalar;

	// scalar = 0.3333333333333333333333f;
	trio_multiply_scalar_get(ambient_tmp, 0.1f, mat->shader.ambi_refl);
	trio_multiply_scalar_get(diffuse_tmp, 0.7f, mat->shader.diff_refl);
	trio_multiply_scalar_get(specular_tmp, 0.2f, mat->shader.spec_refl);
	trio_add3_get(mat->shader.combined, ambient_tmp, diffuse_tmp, specular_tmp);
}
