/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:16:32 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 13:50:53 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	cylinder_main_parse(t_tuple position, t_tuple axis, char **line);
static int	cylinder_size_parse(t_fl *radius, t_fl *height, char **line);

int	cylinder_parse(t_object **object, t_tree *t, char *line)
{
	t_tuple		position;
	t_tuple		axis;
	t_fl		diameter;
	t_fl		height;
	int			flag;

	if (!object || !t || !line)
		return (ft_error(EINVAL, "cylinder_parse"));
	flag = cylinder_main_parse(position, axis, &line);
	if (flag != SUCCESS)
		return (flag);
	flag = cylinder_size_parse(&diameter, &height, &line);
	if (flag != SUCCESS)
		return (flag);
	if (cylinder_new(object, position, axis, t) != SUCCESS
		|| cylinder_resize(*object, diameter / 2.0f, height) != SUCCESS)
		return (ft_error(EINHERIT, "cylinder_parse"));
	return (flag);
}

static int	cylinder_main_parse(t_tuple position, t_tuple axis, char **line)
{
	int			flag;

	if (next_var_get(line, NULL) != SUCCESS || !**line)
		return (rt_invalid(**line));
	flag = ft_atopoint(position, *line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(line, ft_isfloat) != SUCCESS || !**line)
		return (rt_invalid(**line));
	flag = ft_atovector(axis, *line);
	if (flag != SUCCESS)
		return (flag);
	return (SUCCESS);
}

static int	cylinder_size_parse(t_fl *diameter, t_fl *height, char **line)
{
	int			flag;

	if (next_var_get(line, ft_isfloat) != SUCCESS || !**line)
		return (rt_invalid(**line));
	flag = parser_atof(diameter, *line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(line, ft_isfloat) != SUCCESS || !**line)
		return (rt_invalid(**line));
	flag = parser_atof(height, *line);
	return (flag);
}
