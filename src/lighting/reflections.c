/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:57:03 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/13 11:58:55 by jvalkama         ###   ########.fr       */
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
	t_fl	scalar;

	if (light_dot < 0)
		color_new(mat->shader.diff_refl, 0, 0, 0);
	else
	{
		scalar = light_dot * mat->diff_light;
		trio_multiply_scalar_get(mat->shader.diff_refl, \
scalar, mat->shader.eff_color);
	}
}

void	reflection_specular(t_material *mat, t_light *light, t_fl eye_dot)
{
	t_fl	scalar;

	if (light)
	{
		scalar = mat->spec_light * pow(eye_dot, mat->shine);
		trio_multiply_scalar_get(mat->shader.spec_refl, \
scalar, light->intensity);
	}
	else
		color_new(mat->shader.spec_refl, 0, 0, 0);
}

void	reflecton_ambient(t_material *mat, t_light *light)
{
	trio_multiply_get(mat->shader.ambi_refl, \
mat->shader.eff_color, &mat->ambi_light);
}