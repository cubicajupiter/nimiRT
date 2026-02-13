/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:14:28 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 16:02:30 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int sphere_parse(t_object **object, t_tree *t, char *line);
static int plane_parse(t_object **object, t_tree *t, char *line);
static int cylinder_parse(t_object **object, t_tree *t, char *line);
static int color_parse(t_object *object, t_tree *t, char *line);

int	objects_parse(t_tree *t, char *line)
{
	char		*object_info;
	t_object	*object;
	int			flag;

	if (!t || !line)
		return (ft_error(EINVAL, "objects_parse"));
	if (!line[2] || (!ft_strncmp(line, "sp ", 3) && !ft_strncmp(line, "pl ", 3)
		&& !ft_strncmp(line, "cy ", 3)) || !valid_rt_data(line + 2))
		return (FAIL);
	object_info = line + 2;
	object = NULL;
	flag = SUCCESS;
	if (*line == 's')
		flag = sphere_parse(&object, t, object_info);
	else if (*line == 'p')
		flag = plane_parse(&object, t, object_info);
	else if (*line == 'c')
		flag = cylinder_parse(&object, t, object_info);
	if (flag != SUCCESS)
		return (flag);
	if (object)
		if (color_parse(object, t, line) != SUCCESS)
			return (ft_error(EINHERIT, "objects_parse"));
	return (SUCCESS);
}

static int color_parse(t_object *object, t_tree *t, char *line)
{
	int	flag;

	if (!object || !t || !line)
		return (ft_error(EINVAL, "color_parse"));
	while (*line)
		line++;
	line--;
	while (*line && ft_isspace(*line))
		line--;
	while (*line && (ft_isdigit(*line) || *line == ','))
		line--;
	line++;
	flag = ft_atotrio(object->material.color, line);
	return (flag);
}

static int sphere_parse(t_object **object, t_tree *t, char *line)
{
	t_tuple		position;
	t_fl		diameter;
	int			flag;

	if (!object || !t || !line)
		return (ft_error(EINVAL, "sphere_parse"));
	if (next_var_get(&line, NULL) != SUCCESS)
		return (FAIL);
	flag = ft_atopoint(position, line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS)
		return (FAIL);
	flag = ft_atof(line, &diameter);
	if (flag != SUCCESS)
		return (flag);
	if (sphere_new(object, position, diameter / 2.0f, t) != SUCCESS)
		return (ft_error(EINHERIT, "sphere_parse"));
	return (SUCCESS);
}

static int plane_parse(t_object **object, t_tree *t, char *line)
{
	t_tuple		point;
	t_tuple		vector;
	int			flag;

	if (!object || !t || !line)
		return (ft_error(EINVAL, "plane_parse"));
	if (next_var_get(&line, NULL) != SUCCESS)
		return (FAIL);
	flag = ft_atopoint(point, line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS)
		return (FAIL);
	flag = ft_atovector(vector, line);
	if (flag != SUCCESS)
		return (flag);
	// if (plane_new(object, position, diameter / 2.0f, t) != SUCCESS)
	// 	return (ft_error(EINHERIT, "sphere_parse"));
	return (SUCCESS);
}

static int cylinder_parse(t_object **object, t_tree *t, char *line)
{
	t_tuple		position;
	t_tuple		axis;
	t_fl		diameter;
	t_fl		height;
	int			flag;

	if (!object || !t || !line)
		return (ft_error(EINVAL, "cylinder_parse"));
	if (next_var_get(&line, NULL) != SUCCESS)
		return (FAIL);
	flag = ft_atopoint(position, line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS)
		return (FAIL);
	flag = ft_atovector(axis, line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS)
		return (FAIL);
	flag = ft_atof(line, &diameter);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS)
		return (FAIL);
	flag = ft_atof(line, &height);
	// if (cylinder_new(object, position, diameter / 2.0f, t) != SUCCESS)
	// 	return (ft_error(EINHERIT, "sphere_parse"));
	return (SUCCESS);
}
