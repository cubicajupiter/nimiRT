/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:19:43 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 10:58:15 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

int	float_formatted_print(char *name, t_fl value)
{
	if (printf("%15s\t", name) < 0)
	{
		ft_error(EINHERIT, "printf");
		return (ft_error(EINHERIT, "float_formatted_print"));
	}
	if (float_print(value) != SUCCESS)
		return (ft_error(EINHERIT, "float_formatted_print"));
	if (printf("\n") < 0)
	{
		ft_error(EINHERIT, "printf");
		return (ft_error(EINHERIT, "float_formatted_print"));
	}
	return (SUCCESS);
}

int	int_formatted_print(char *name, int value)
{
	if (printf("%15s\t", name) < 0)
	{
		ft_error(EINHERIT, "printf");
		return (ft_error(EINHERIT, "int_formatted_print"));
	}
	if (int_print(value) != SUCCESS)
		return (ft_error(EINHERIT, "int_formatted_print"));
	if (printf("\n") < 0)
	{
		ft_error(EINHERIT, "printf");
		return (ft_error(EINHERIT, "int_formatted_print"));
	}
	return (SUCCESS);
}

int	main_variables_print(t_scene *s)
{
	if (!s)
		return (ft_error(EINVAL, "main_variables_print"));
	if (printf("SCENE DATA\n") < 0
		|| printf("-AMBIENT\n") < 0
		|| float_formatted_print("brightness", s->ambient.brightness) != SUCCESS
		|| color_print(s->ambient.color) != SUCCESS
		|| printf("-CAMERA\n") < 0
		|| tuple_print(s->camera.ray[ORIGIN]) != SUCCESS
		|| tuple_print(s->camera.ray[DIRECTION]) != SUCCESS
		|| float_formatted_print("field-of-view", s->camera.fov) != SUCCESS
		|| printf("-LIGHT\n") < 0
		|| tuple_print(s->light.point) != SUCCESS
		|| float_formatted_print("brightness", s->light.brightness) != SUCCESS
		|| color_print(s->light.color) != SUCCESS)
		return (ft_error(EINHERIT, "main_variables_print"));
	return (SUCCESS);
}

int	scene_data_print(t_tree *t)
{
	t_scene	*s;

	if (!t || !t->scene)
		return (ft_error(EINVAL, "scene_data_print"));
	s = t->scene;
	if (main_variables_print(s) != SUCCESS
		|| objects_print(s) != SUCCESS)
		return (ft_error(EINHERIT, "scene_data_print"));
	// TODO: Complete function
	return (SUCCESS);
}
