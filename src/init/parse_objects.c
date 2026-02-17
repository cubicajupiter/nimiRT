/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:14:28 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 14:00:32 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	sphere_parse(t_object **object, t_tree *t, char *line);
static int	plane_parse(t_object **object, t_tree *t, char *line);

static int	objects_parse_helper(t_tree *t, char *line)
{
	t_object	*object;
	char		*object_info;
	int			flag;

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
		flag = color_parse(object, t, object_info);
	if (flag == FAIL)
		return (FAIL);
	if (flag == ERROR)
		return (ft_error(EINHERIT, "objects_parse_helper"));
	return (SUCCESS);
}

int	objects_parse(t_tree *t, char *line)
{
	int			flag;

	if (!t || !line)
		return (ft_error(EINVAL, "objects_parse"));
	if (!line[2] || (!ft_strncmp(line, "sp", 2) && !ft_strncmp(line, "pl", 2)
			&& !ft_strncmp(line, "cy", 2)))
		return (rt_invalid(*line));
	if (!valid_rt_data(line + 2))
		return (FAIL);
	flag = objects_parse_helper(t, line);
	if (flag == FAIL)
		return (FAIL);
	if (flag == ERROR)
		return (ft_error(EINHERIT, "objects_parse"));
	return (SUCCESS);
}

static int	sphere_parse(t_object **object, t_tree *t, char *line)
{
	t_tuple		position;
	t_fl		diameter;
	int			flag;

	if (!object || !t || !line)
		return (ft_error(EINVAL, "sphere_parse"));
	if (next_var_get(&line, NULL) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = ft_atopoint(position, line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = parser_atof(&diameter, line);
	if (flag != SUCCESS)
		return (flag);
	if (sphere_new(object, position, diameter / 2.0f, t) != SUCCESS)
		return (ft_error(EINHERIT, "sphere_parse"));
	return (SUCCESS);
}

static int	plane_parse(t_object **object, t_tree *t, char *line)
{
	t_tuple		point;
	t_tuple		vector;
	int			flag;

	if (!object || !t || !line)
		return (ft_error(EINVAL, "plane_parse"));
	if (next_var_get(&line, NULL) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = ft_atopoint(point, line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = ft_atovector(vector, line);
	if (flag != SUCCESS)
		return (flag);
	if (plane_new(object, point, vector, t) != SUCCESS)
		return (ft_error(EINHERIT, "plane_parse"));
	return (SUCCESS);
}
