/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:24:23 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/20 15:53:57 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	plane_new(t_object **dst, t_trio pos, t_trio vector, t_tree *t)
{
	t_plane		*plane;
	t_object	object;
	t_object	*tmp;

	if (!pos || !vector || !t)
		return (ft_error(EINVAL, "plane_new"));
	plane = NULL;
	if (ft_arena_alloc(t->a_buf, (void **)&plane, sizeof(t_plane)) != SUCCESS
		|| ft_memset(&object, 0, sizeof(t_object)) == NULL)
		return (ft_error(EINHERIT, "plane_new"));
	object.type = PLANE;
	object.plane = plane;
	material_default(&object.material);
	plane->id = t->scene->objects->len;
	if (point_new(plane->point, 0, 0, 0) != SUCCESS
		|| vector_new(plane->vector, vector[X], vector[Y], vector[Z]) != SUCCESS
		|| translation(plane->transform, pos[X], pos[Y], pos[Z]) != SUCCESS
		|| vec_push(t->scene->objects, &object) != SUCCESS)
		return (ft_error(EINHERIT, "plane_new"));
	tmp = vec_get(t->scene->objects, plane->id);
	if (dst)
		*dst = tmp;
	return (SUCCESS);
}
