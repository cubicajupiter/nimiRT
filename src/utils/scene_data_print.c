/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:19:43 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/12 17:46:46 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	scene_data_print(t_tree *t)
{
	t_scene	*s;
	if (!t || !t->scene)
		return (ft_error(EINVAL, "scene_data_print"));
	s = t->scene;
	printf("SCENE DATA\n");
	printf(" - AMBIENT LIGHT\n");
	printf("brightness\t %f\n", s->ambient.brightness);
	printf("\t");
	color_print(s->ambient.color);
	printf(" - CAMERA\n");
	printf("\t");
	tuple_print(s->camera.ray[ORIGIN]);
	printf("\t");
	tuple_print(s->camera.ray[DIRECTION]);
	printf("field-of-view\t %d\n", s->camera.fov);
	// TODO: Complete function
	return (SUCCESS);
}
