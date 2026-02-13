/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:13:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 15:12:54 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

static int	ambient_parse(t_tree *t, char *line);
static int	camera_parse(t_tree *t, char *line);
static int	light_parse(t_tree *t, char *line);

int	main_info_parse(t_tree *t, char *line)
{
	char	*element_info;

	if (!t || !line)
		return (ft_error(EINVAL, "main_info_parse"));
	if (!line[1] || (!ft_strncmp(line, "A ", 2) && !ft_strncmp(line, "C ", 2)
		&& !ft_strncmp(line, "L ", 2)))
		return (FAIL);
	element_info = line + 1;
	if (!valid_rt_data(element_info))
		return (FAIL);
	if (*line == 'A')
		return (ambient_parse(t, element_info));
	else if (*line == 'C')
		return (camera_parse(t, element_info));
	else if (*line == 'L')
		return (light_parse(t, element_info));
	return (FAIL);
}

static int	ambient_parse(t_tree *t, char *line)
{
	int	flag;

	if (!t || !line)
		return (ft_error(EINVAL, "ambient_parse"));
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

static int	camera_parse(t_tree *t, char *line)
{
	int	flag;

	if (!t || !line)
		return (ft_error(EINVAL, "camera_parse"));
	if (next_var_get(&line, NULL) != SUCCESS)
		return (FAIL);
	flag = ft_atopoint(t->scene->camera.ray[ORIGIN], line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS)
		return (FAIL);
	flag = ft_atovector(t->scene->camera.ray[DIRECTION], line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS)
		return (FAIL);
	flag = ft_atoi(line, &t->scene->camera.fov);
	return (flag);
}

// if (flag != SUCCESS) // NOTE: Add to end of parse_light() for bonus
// 	return (flag);
// if (next_var_get(&line, ft_isfloat) != SUCCESS)
// 	return (FAIL);
// flag = ft_atotrio(t->scene->light.color, line);
static int	light_parse(t_tree *t, char *line)
{
	int	flag;

	if (!t || !line)
		return (ft_error(EINVAL, "light_parse"));
	if (next_var_get(&line, NULL) != SUCCESS)
		return (FAIL);
	flag = ft_atopoint(t->scene->light.point, line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS)
		return (FAIL);
	flag = ft_atof(line, &t->scene->light.brightness);
	return (flag);
}
