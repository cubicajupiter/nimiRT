/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:19:43 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/12 17:36:20 by thblack-         ###   ########.fr       */
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
	printf("brightness\t%f\n", s->ambient.brightness);
	color_print(s->ambient.color);
	printf(" - CAMERA\n");
	tuple_print(s->camera.ray[ORIGIN]);
	tuple_print(s->camera.ray[DIRECTION]);
	// TODO: Complete function
	return (SUCCESS);
}
