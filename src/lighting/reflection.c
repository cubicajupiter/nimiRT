/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:06:36 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/11 15:39:40 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	reflection(t_tuple dst, t_tuple in, t_tuple normal)
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

int	reflection_ambient(t_tuple dst, t_tuple in, t_tuple normal)
{
	;
}

int	reflection_diffuse(t_tuple dst, t_tuple in, t_tuple normal)
{
	;
}

int	reflection_specular(t_tuple dst, t_tuple in, t_tuple normal)
{
	;
}

int	material_new(t_material *dst)
{
	dst->ambient = 0.1;
	dst->diffuse = 0.9;
	dst->specular = 0.9;
	dst->shininess = 200.0;
}