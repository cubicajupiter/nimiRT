/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:09:47 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 18:13:07 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	materials_set(t_scene *s)
{
	t_object	*object;
	t_material	*material;
	size_t		i;

	if (!s)
		return (ft_error(EINVAL, "materials_set"));
	i = 0;
	while (i < s->objects->len)
	{
		object = vec_get(s->objects, i);
		material = &object->material;
		trio_multiply_get(material->shader.eff_color,
			material->color, s->light.color);
		trio_multiply_get(material->shader.ambi_refl, s->ambient.color,
			material->shader.eff_color);
		i++;
	}
	return (SUCCESS);
}
