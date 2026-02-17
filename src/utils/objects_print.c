/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:10:52 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 10:23:06 by thblack-         ###   ########.fr       */
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

int	plane_print(t_plane *plane)
{
	t_matrix	*tmp;
	t_tuple		position;

	tmp = &plane->transform;
	if (printf("-plane\n") < 0
		|| int_formatted_print("id", plane->id) != SUCCESS
		|| point_new(position,
			(*tmp)[0][3], (*tmp)[1][3], (*tmp)[2][3]) != SUCCESS
		|| tuple_print(position) != SUCCESS
		|| tuple_print(plane->vector) != SUCCESS)
		return (ft_error(EINHERIT, "plane_print"));
	return (SUCCESS);
}

int	cylinder_print(t_cylinder *cylinder)
{
	t_matrix	*tmp;
	t_tuple		position;

	tmp = &cylinder->transform;
	if (printf("-cylinder\n") < 0
		|| int_formatted_print("id", cylinder->id) != SUCCESS
		|| point_new(position,
			(*tmp)[0][3], (*tmp)[1][3], (*tmp)[2][3]) != SUCCESS
		|| tuple_print(position) != SUCCESS
		|| tuple_print(cylinder->axis) != SUCCESS
		|| float_formatted_print("radius", cylinder->radius) != SUCCESS
		|| float_formatted_print("height", cylinder->height) != SUCCESS)
		return (ft_error(EINHERIT, "cylinder_print"));
	return (SUCCESS);
}

int	object_material_print(t_material *material)
{
	if (!material)
		return (ft_error(EINVAL, "object_material_print"));
	if (color_print(material->color) != SUCCESS)
		return (ft_error(EINHERIT, "object_material_print"));
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
			if (sphere_print(object->sphere) != SUCCESS)
				return (ft_error(EINHERIT, "objects_print"));
		if (object->type == PLANE)
			if (plane_print(object->plane) != SUCCESS)
				return (ft_error(EINHERIT, "objects_print"));
		if (object->type == CYLINDER)
			if (cylinder_print(object->cylinder) != SUCCESS)
				return (ft_error(EINHERIT, "objects_print"));
		if (object_material_print(&object->material) != SUCCESS)
			return (ft_error(EINHERIT, "objects_print"));
		i++;
	}
	return (SUCCESS);
}
