/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:57:03 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/13 17:41:17 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "lighting.h"

int	reflection_get(t_tuple dst, t_tuple in, t_tuple normal)
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

void	reflection_diffuse(t_material *mat, t_fl light_dot)
{
	t_trio		weight;

	if (light_dot >= 0)
	{
		trio_multiply_scalar_get(weight, mat->diff_light, mat->shader.eff_color);
		trio_multiply_scalar_get(mat->shader.diff_refl, light_dot, weight);
	}
	else
		color_new(mat->shader.diff_refl, 0, 0, 0);
}

void	reflection_specular(t_material *mat, t_light *light, t_fl eye_dot)
{
	t_trio		weight;
	t_fl		factor;

	if (light)
	{
		factor = pow(eye_dot, mat->shine);
		trio_multiply_scalar_get(weight, mat->spec_light, light->color);
		trio_multiply_scalar_get(mat->shader.spec_refl, factor, weight);
	} 
	else
		color_new(mat->shader.spec_refl, 0, 0, 0);
}

void	reflection_ambient(t_material *mat)
{
	trio_multiply_scalar_get(mat->shader.ambi_refl, mat->ambi_light, \
mat->shader.eff_color);
}
