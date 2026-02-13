/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:10:52 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 14:53:53 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	sphere_print(t_sphere *sphere)
{
	t_matrix	*tmp;
	t_tuple		position;

	tmp = &sphere->transform;
	if (printf("-SPHERE\n") < 0
		|| int_formatted_print("id", sphere->id) != SUCCESS
		|| point_new(position,
			(*tmp)[0][3], (*tmp)[1][3], (*tmp)[2][3]) != SUCCESS
		|| tuple_print(position) != SUCCESS
		|| float_formatted_print("radius", sphere->radius) != SUCCESS)
		return (ft_error(EINHERIT, "sphere_print"));
	return (SUCCESS);
}

int	object_surface_variables_print(t_object *object)
{
	(void)object;
	return (SUCCESS);
}

int	objects_print(t_scene *s)
{
	size_t		i;
	t_object	*object;

	i = 0;
	while (i < s->objects->len)
	{
		object = vec_get(s->objects, i);
		if (object->type == SPHERE)
			if (sphere_print(object->sphere) != SUCCESS
				|| object_surface_variables_print(object) != SUCCESS)
				return (ft_error(EINHERIT, "objects_print"));
		i++;
	}
	return (SUCCESS);
}
