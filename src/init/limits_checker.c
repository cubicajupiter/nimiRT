/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:23:47 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 13:23:41 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "messages.h"

static bool	rt_out_of_limits(char *value);

static bool	valid_01_float(t_fl nbr, char *value)
{
	if (nbr < 0.0f || nbr > 1.0f)
		return (rt_out_of_limits(value));
	return (true);
}

static bool	valid_color(t_trio color, char *value)
{
	if (color[R] < 0.0f || color[R] > 1.0f
		|| color[G] < 0.0f || color[G] > 1.0f
		|| color[B] < 0.0f || color[B] > 1.0f)
		return (rt_out_of_limits(value));
	return (true);
}

static bool	valid_vector(t_tuple vector, char *value)
{
	if (vector[W] != VECTOR
		|| vector[X] < -1.0f || vector[X] > 1.0f
		|| vector[Y] < -1.0f || vector[Y] > 1.0f
		|| vector[Z] < -1.0f || vector[Z] > 1.0f)
		return (rt_out_of_limits(value));
	return (true);
}

static bool	object_checker(t_object *object)
{
	if (object->type == PLANE
		&& !valid_vector(object->plane->vector, "plane vector"))
		return (false);
	if (object->type == CYLINDER
		&& !valid_vector(object->cylinder->axis, "cylinder axis"))
		return (false);
	if (!valid_color(object->material.color, "object color"))
		return (false);
	return (true);
}

bool	values_within_limits(t_scene *s)
{
	t_object	*object;
	size_t		i;

	if (!s)
		return (false);
	if (!valid_01_float(s->ambient.brightness, "ambient lighting")
		|| !valid_color(s->ambient.color, "ambient color")
		|| !valid_vector(s->camera.ray[DIRECTION], "camera vector")
		// || !valid_point(s->light->point) // NOTE: Infinity check??
		|| !valid_01_float(s->light.brightness, "light brightness")
		|| !valid_color(s->light.color, "light color"))
		return (false);
	if (s->camera.fov < 0.0f || s->camera.fov > PI)
		return (rt_out_of_limits("camera fov"));
	i = 0;
	while (i < s->objects->len)
	{
		object = vec_get(s->objects, i);
		if (!object_checker(object))
			return (false);
		i++;
	}
	return (true);
}

/*
rt_out_of_limits()
Prints a custom error message letting the user know where an *.rt file might
contain a bad syntax.
*/
static bool	rt_out_of_limits(char *value)
{
	ft_putendl_fd("Error\n", 2);
	if (value)
	{
		ft_putstr_fd("Value of ", 2);
		ft_putstr_fd(value, 2);
		ft_putendl_fd(" outside of limits", 2);
	}
	ft_putendl_fd(MSG_INVALID_RT, 2);
	return (false);
}
