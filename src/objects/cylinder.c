/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:24:11 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 17:57:43 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

int	cylinder_new(t_object **dst, t_tuple pos, t_tuple vector, t_tree *t)
{
	t_cylinder	*cylinder;
	t_object	object;
	t_object	*tmp;

	if (!pos || !vector || !t)
		return (ft_error(EINVAL, "cylinder_new"));
	cylinder = NULL;
	if (ft_arena_alloc(t->a_buf, (void **)&cylinder,
			sizeof(t_cylinder)) != SUCCESS
		|| ft_memset(&object, 0, sizeof(t_object)) == NULL)
		return (ft_error(EINHERIT, "cylinder_new"));
	object.type = CYLINDER;
	object.cylinder = cylinder;
	material_default(&object.material);
	cylinder->id = t->scene->objects->len;
	if (vector_new(cylinder->axis, vector[X], vector[Y], vector[Z]) != SUCCESS
		|| point_new(cylinder->center, 0, 0, 0) != SUCCESS
		|| translation(cylinder->transform, pos[X], pos[Y], pos[Z]) != SUCCESS
		|| vec_push(t->scene->objects, &object) != SUCCESS)
		return (ft_error(EINHERIT, "cylinder_new"));
	tmp = vec_get(t->scene->objects, cylinder->id);
	if (dst)
		*dst = tmp;
	return (SUCCESS);
}

int	cylinder_resize(t_object *dst, t_fl radius, t_fl height)
{
	t_cylinder	*cylinder;

	if (!dst)
		return (ft_error(EINVAL, "cylinder_resize"));
	cylinder = dst->cylinder;
	if (ft_dtor(&cylinder->radius, radius) != SUCCESS)
		return (ft_error(EINHERIT, "cylinder_resize"));
	cylinder->height = height;
	return (SUCCESS);
}
