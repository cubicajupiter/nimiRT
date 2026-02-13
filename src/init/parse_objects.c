/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:14:28 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 15:14:43 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int sphere_parse(t_object **object, t_tree *t, char *line);
// static int parse_plane(t_tree *t, char *line);
// static int parse_cylinder(t_tree *t, char *line);
static int material_parse(t_object **object, t_tree *t, char *line);

int	objects_parse(t_tree *t, char *line)
{
	char		*object_info;
	t_object	*object;

	if (!t || !line)
		return (ft_error(EINVAL, "objects_parse"));
	if (!line[2] || (!ft_strncmp(line, "sp ", 3) && !ft_strncmp(line, "pl ", 3)
		&& !ft_strncmp(line, "cy ", 3)))
		return (FAIL);
	object_info = line + 2;
	object = NULL;
	if (!valid_rt_data(object_info))
		return (FAIL);
	if (*line == 's')
		return (sphere_parse(&object, t, object_info));
	// else if (*line == 'p')
	// 	return (parse_plane(t, line));
	// else if (*line == 'c')
	// 	return (parse_cylinder(t, line));
	if (object)
		if (material_parse(&object, t, line) != SUCCESS)
			return (ft_error(EINHERIT, "parse_objects"));
	return (SUCCESS); // FIXME: Delete after other functions created
}

static int material_parse(t_object **object, t_tree *t, char *line)
{
}

static int sphere_parse(t_object **object, t_tree *t, char *line)
{
	t_tuple		position;
	t_fl		diameter;
	t_trio		color;
	int			flag;

	if (!t || !line)
		return (ft_error(EINVAL, "parse_sphere"));
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
	if (next_var_get(&line, ft_isfloat) != SUCCESS)
		return (FAIL);
	flag = ft_atotrio(color, line);
	if (sphere_new(object, position, diameter / 2.0f, t) != SUCCESS)
		return (ft_error(EINHERIT, "parse_sphere"));
	return (flag);
}

// static int parse_plane(t_tree *t, char *line)
// {
// }
//
// static int parse_cylinder(t_tree *t, char *line)
// {
// }
