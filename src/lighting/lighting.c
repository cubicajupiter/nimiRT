/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:21:41 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/13 11:58:54 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "lighting.h"

static t_fl	eye_vec_dp(t_tuple l_v, t_tuple nl_v, t_tuple r_v, t_tuple *ini_vs);

/*
	Parameters:
	- the material,
	- the point being illuminated, 
	- the light source,
	- the eye and normal vectors as a pointer array[2]
*/
int	lighting(t_material *mat, t_light *light, t_tuple point, t_tuple *vectors)
{
	t_fl		light_dot;
	t_fl		eye_dot;
	t_tuple		refl_v;
	t_tuple		neglight_v;
	t_tuple		light_v;

	tuple_minus_get(light_v, light->pos, point);
	normalize_apply(light_v);
	vector_dot(&light_dot, light_v, vectors[NORMAL]);
	trio_multiply_get(mat->shader->eff_color, mat->color, light->intensity);
	reflection_ambient(mat, light);
	if (light_dot < 0)
		reflection_specular(mat, NULL, eye_dot);
	else
	{
		eye_dot = eye_vec_dp(light_v, neglight_v, refl_v, vectors);
		if (eye_dot <= 0)
			reflection_specular(mat, NULL, eye_dot);
		else
			reflection_specular(mat, light, eye_dot);
	}
	reflection_diffuse(mat, light_dot);
	trio_add3(mat->shader->combined, \
mat->shader->ambi_refl, mat->shader->diff_refl, mat->shader->spec_refl);
}

static t_fl	eye_vec_dp(\
t_tuple light_v, t_tuple neglight_v, t_tuple refl_v, t_tuple *initial_vectors)
{
	t_fl		eye_dot_product;

	vector_negate(neglight_v, light_v);
	reflection(refl_v, neglight_v, initial_vectors[NORMAL]);
	vector_dot(&eye_dot_product, refl_v, initial_vectors[EYE]);
	return (eye_dot_product);
}