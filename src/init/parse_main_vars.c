/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:13:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/12 14:16:05 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

static int	parse_ambient(t_tree *t, char *line);
static int	parse_camera(t_tree *t, char *line);
// static int	parse_light(t_tree *t, char *line);

bool	valid_rt_vars(char *line)
{
	while (*line)
	{
		if (!ft_isfloat(*line) && !ft_isspace(*line) && *line != ',')
			return (false);
		line++;
	}
	return (true);
}

int	parse_main_vars(t_tree *t, char *line)
{
	char	*element_info;

	if (!t || !line)
		return (ft_error(EINVAL, "parse_main_vars"));
	if ((*line != 'A' && *line != 'C' && *line != 'L') || !line[1])
		return (FAIL);
	element_info = line + 1;
	if (!valid_rt_vars(element_info))
		return (FAIL);
	if (*line == 'A')
		return (parse_ambient(t, element_info));
	else if (*line == 'C')
		return (parse_camera(t, element_info));
	// else if (*line == 'L')
	// 	return (parse_light(t, line));
	return (SUCCESS); // FIXME: Delete after other functions created
}

int	next_var_get(char **line, int (*increment_beyond_type)(int))
{
	char	*tmp;

	if (!line)
		return (ft_error(EINVAL, "next_var_get"));
	tmp = *line;
	if (increment_beyond_type)
		while (*tmp && (increment_beyond_type(*tmp) || *tmp == ','))
			tmp++;
	while (*tmp && ft_isspace(*tmp))
		tmp++;
	if (!tmp)
		return (FAIL);
	*line = tmp;
	return (SUCCESS);
}

static int	parse_ambient(t_tree *t, char *line)
{
	int	flag;

	if (next_var_get(&line, NULL) != SUCCESS)
		return (FAIL);
	flag = ft_atof(line, &t->scene->ambient.brightness);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS)
		return (FAIL);
	flag = ft_atotrio(t->scene->ambient.color, line);
	return (flag);
}

static int	parse_camera(t_tree *t, char *line)
{
	int	flag;

	if (next_var_get(&line, NULL) != SUCCESS)
		return (FAIL);
	flag = ft_atotuple(t->scene->camera.ray[ORIGIN], line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS)
		return (FAIL);
	flag = ft_atotuple(t->scene->camera.ray[DIRECTION], line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS)
		return (FAIL);
	flag = ft_atoi(line, &t->scene->camera.fov);
	return (flag);
}

// static int	parse_light(t_tree *t, char *line)
// {
// }
