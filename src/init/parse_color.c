/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:59:52 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 14:00:38 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	var_count_get(int *var_count, t_object *object);

int	color_parse(t_object *object, t_tree *t, char *line)
{
	int	var_count;
	int	flag;

	if (!object || !t || !line)
		return (ft_error(EINVAL, "color_parse"));
	var_count_get(&var_count, object);
	while (var_count-- > 0)
	{
		if (next_var_get(&line, ft_isfloat) != SUCCESS || !*line)
			return (rt_invalid(*line));
	}
	flag = ft_atotrio(object->material.color, line);
	if (flag == FAIL)
		return (rt_invalid(*line));
	if (flag == ERROR)
		return (ft_error(EINHERIT, "objects_parse"));
	return (SUCCESS);
}

static int	var_count_get(int *var_count, t_object *object)
{
	int	tmp;

	if (!var_count || !object)
		return (ft_error(EINVAL, "var_count_get"));
	tmp = 0;
	if (object->type == SPHERE || object->type == PLANE)
		tmp = 3;
	if (object->type == CYLINDER)
		tmp = 5;
	*var_count = tmp;
	return (SUCCESS);
}
