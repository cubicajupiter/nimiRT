/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:13:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 13:49:15 by thblack-         ###   ########.fr       */
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
	if (!line[1] || (*line != 'A' && *line != 'C' && *line != 'L'))
		return (rt_invalid(*line));
	element_info = line + 1;
	if (!valid_rt_data(element_info))
		return (FAIL);
	if (*line == 'A' && t->scene->ambient.set == false)
		return (ambient_parse(t, element_info));
	else if (*line == 'C' && t->scene->camera.set == false)
		return (camera_parse(t, element_info));
	else if (*line == 'L' && t->scene->light.set == false)
		return (light_parse(t, element_info));
	else
		return (rt_invalid(*line));
	return (SUCCESS);
}

static int	ambient_parse(t_tree *t, char *line)
{
	int	flag;

	if (!t || !line)
		return (ft_error(EINVAL, "ambient_parse"));
	if (next_var_get(&line, NULL) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = parser_atof(&t->scene->ambient.brightness, line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = ft_atotrio(t->scene->ambient.color, line);
	if (flag == FAIL)
		return (rt_invalid(*line));
	if (flag == ERROR)
		return (ft_error(EINHERIT, "ambient_parse"));
	t->scene->ambient.set = true;
	return (SUCCESS);
}

static int	camera_parse(t_tree *t, char *line)
{
	int	fov_degrees;
	int	flag;

	if (!t || !line)
		return (ft_error(EINVAL, "camera_parse"));
	if (next_var_get(&line, NULL) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = ft_atopoint(t->scene->camera.ray[ORIGIN], line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = ft_atovector(t->scene->camera.ray[DIRECTION], line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = parser_atoi(&fov_degrees, line);
	if (flag != SUCCESS)
		return (flag);
	flag = ft_dtor(&t->scene->camera.fov, fov_degrees);
	if (flag == SUCCESS)
		t->scene->camera.set = true;
	return (flag);
}

// NOTE: Add to end of parse_light() for bonus and scale for brightness
// if (flag != SUCCESS)
// 	return (flag);
// if (next_var_get(&line, ft_isfloat) != SUCCESS)
// 	return (FAIL);
// flag = ft_atotrio(t->scene->light.color, line);
static int	light_parse(t_tree *t, char *line)
{
	t_fl	tmp;
	int		flag;

	if (!t || !line)
		return (ft_error(EINVAL, "light_parse"));
	if (next_var_get(&line, NULL) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = ft_atopoint(t->scene->light.point, line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = parser_atof(&tmp, line);
	if (flag != SUCCESS)
		return (flag);
	t->scene->light.brightness = tmp;
	if (color_new(t->scene->light.color, tmp, tmp, tmp) != SUCCESS)
		return (ft_error(EINHERIT, "light_parse"));
	t->scene->light.set = true;
	return (flag);
}
