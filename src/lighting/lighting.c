/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:21:41 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/12 13:47:39 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "lighting.h"

static void	reflection_diffuse(t_material *m, t_fl light_dot);
static void	reflection_specular(t_material *m, t_light *l, t_fl eye_dot);
static t_fl	eye_vec_dp(t_tuple l_v, t_tuple nl_v, t_tuple r_v, t_tuple *ini_vs);
static int	reflection(t_tuple dst, t_tuple in, t_tuple normal);

/*
	Parameters:
	the material, (right now t_object containing material)
	the point being illuminated, 
	the light source,
	the eye and normal vectors from the Phong reflection model
*/
int	lighting(t_material *m, t_tuple point, t_light *l, t_tuple *vectors)
{
	t_fl		light_dot;
	t_fl		eye_dot;
	t_tuple		r_vec;
	t_tuple		nl_vec;
	t_tuple		l_vec;

	tuple_minus_get(l_vec, l->pos, point);
	normalize_apply(l_vec);
	vector_dot(&light_dot, l_vec, vectors[NORMAL]);
	trio_multiply_get(m->cs->eff_color, m->color, l->intensity);
	trio_multiply_scalar_get(m->cs->ambi, m->ambi_l, m->cs->eff_color);
	if (light_dot < 0)
	{
		color_new(m->cs->diff, 0, 0, 0);
		color_new(m->cs->spec, 0, 0, 0);
	}
	else
	{
		reflection_diffuse(m, light_dot);
		eye_dot = eye_vec_dp(l_vec, nl_vec, r_vec, vectors);
		if (eye_dot <= 0)
			color_new(m->cs->spec, 0, 0, 0);
		else
			reflection_specular(m, l, eye_dot);
	}
	trio_add3(m->cs->comb, m->cs->ambi, m->cs->diff, m->cs->spec);
}

static void	reflection_diffuse(t_material *m, t_fl light_dot)
{
	t_fl	scalar;

	scalar = light_dot * m->diff_l;
	trio_multiply_scalar_get(m->cs->diff, scalar, m->cs->eff_color);
}

static void	reflection_specular(t_material *m, t_light *l, t_fl eye_dot)
{
	t_fl	scalar;

	scalar = m->spec_l * pow(eye_dot, m->shine);
	trio_multiply_scalar_get(m->cs->spec, scalar, l->intensity);
}

static t_fl	eye_vec_dp(t_tuple l_v, t_tuple nl_v, t_tuple r_v, t_tuple *ini_vs)
{
	t_fl		eye_dot_product;

	vector_negate(nl_v, l_v);
	reflection(r_v, nl_v, ini_vs[NORMAL]);
	vector_dot(&eye_dot_product, r_v, ini_vs[EYE]);
	return (eye_dot_product);
}

static int	reflection(t_tuple dst, t_tuple in, t_tuple normal)
{
	t_tuple		new_normal;
	t_fl		dot_product;

	if (!dst || !in || !normal)
		return (ft_error(EINVAL, "reflection"));
	vector_dot(&dot_product, in, normal);
	vector_multiply_get(new_normal, 2 * dot_product, normal);
	tuple_minus_get(dst, in, new_normal);
	return (SUCCESS);
}