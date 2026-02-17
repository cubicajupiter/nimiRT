/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:21:41 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/17 18:12:11 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "lighting.h"

static void	light_vector_get(t_tuple dst, t_light *light, t_tuple point);
static t_fl	eye_vec_dp(\
t_tuple light_v, t_tuple neglight_v, t_tuple *initial_vectors[]);
static void	combine_reflections(t_material *mat);

/*
	Parameters:
	- the material,
	- the point being illuminated, 
	- the light source,
	- the eye and normal vectors as a pointer array (t_tuple *[2])
*/
int	lighting(t_material *mat, t_light *light, t_tuple point, t_tuple *vectors[])
{
	t_fl		light_dot;
	t_fl		eye_dot;
	t_tuple		light_v;
	t_tuple		neglight_v;

	if (!mat || !light || !point || !vectors)
		return (ft_error(EINVAL, "lighting"));
	// trio_multiply_get(mat->shader.eff_color, mat->color, light->color);
	light_vector_get(light_v, light, point);
	// reflection_ambient(mat, s);
	vector_dot(&light_dot, light_v, *vectors[NORMAL]);
	if (light_dot < 0)
		reflection_specular(mat, NULL, 0.0);
	else
	{
		eye_dot = eye_vec_dp(light_v, neglight_v, vectors);
		if (eye_dot <= 0)
			reflection_specular(mat, NULL, eye_dot);
		else
			reflection_specular(mat, light, eye_dot);
	}
	reflection_diffuse(mat, light_dot);
	combine_reflections(mat);
	return (SUCCESS);
}

static void	light_vector_get(t_tuple dst, t_light *light, t_tuple point)
{
	tuple_minus_get(dst, light->point, point);
	normalize_apply(dst);
}

static t_fl	eye_vec_dp(\
t_tuple light_v, t_tuple neglight_v, t_tuple *initial_vectors[])
{
	t_fl		eye_dot_product;
	t_tuple		refl_v;
 
	vector_negate(neglight_v, light_v);
	reflection_get(refl_v, neglight_v, *initial_vectors[NORMAL]);
	vector_dot(&eye_dot_product, refl_v, *initial_vectors[EYE]);
	return (eye_dot_product);
}

static void	combine_reflections(t_material *mat)
{
	t_trio	ambient_tmp;
	t_trio	diffuse_tmp;
	t_trio	specular_tmp;
	t_fl	scalar;

	scalar = 0.3333333333333333333333f;
	trio_multiply_scalar_get(ambient_tmp, scalar, mat->shader.ambi_refl);
	trio_multiply_scalar_get(diffuse_tmp, scalar, mat->shader.diff_refl);
	trio_multiply_scalar_get(specular_tmp, scalar, mat->shader.spec_refl);
	trio_add3_get(mat->shader.combined, ambient_tmp, diffuse_tmp, specular_tmp);
}
