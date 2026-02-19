/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 13:59:52 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 17:55:18 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	var_count_get(int *var_count, t_object *object);

int	color_parse(t_object *object, t_tree *t, char *line)
{
	int		var_count;
	int		flag;
	char	*nptr;

	if (!object || !t || !line)
		return (ft_error(EINVAL, "color_parse"));
	nptr = line;
	var_count_get(&var_count, object);
	while (var_count-- > 0)
	{
		if (next_var_get(&nptr, ft_isfloat) != SUCCESS)
			return (rt_invalid(*nptr));
		if (!*nptr)
			return (rt_invalid(*line));
	}
	flag = ft_atotrio(object->material.color, nptr);
	if (flag == FAIL)
		return (rt_invalid(*nptr));
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
