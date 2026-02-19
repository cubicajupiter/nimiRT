/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:13:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 14:49:17 by thblack-         ###   ########.fr       */
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
	t_fl	brightness;
	t_trio	color;
	int		flag;

	if (!t || !line)
		return (ft_error(EINVAL, "ambient_parse"));
	if (next_var_get(&line, NULL) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = parser_atof(&brightness, line);
	if (flag != SUCCESS)
		return (flag);
	if (!valid_01_float(brightness, "ambient brightness"))
		return (FAIL);
	if (next_var_get(&line, ft_isfloat) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = ft_atotrio(color, line);
	if (flag == ERROR)
		return (ft_error(EINHERIT, "ambient_parse"));
	if (flag == FAIL || !valid_color(color, "ambient color"))
		return (FAIL);
	if (trio_multiply_scalar_get(t->scene->ambient.color,
			brightness, color) != SUCCESS)
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

static int	light_parse_helper(t_tree *t, char *line)
{
	t_fl	brightness;
	t_trio	color;
	int		flag;

	flag = parser_atof(&brightness, line);
	if (flag != SUCCESS)
		return (flag);
	if (!valid_01_float(brightness, "light brightness"))
		return (FAIL);
	if (next_var_get(&line, ft_isfloat) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = ft_atotrio(color, line);
	if (flag == FAIL)
		return (rt_invalid(*line));
	if (flag == ERROR)
		return (ft_error(EINHERIT, "light_parse"));
	if (!valid_color(color, "light color"))
		return (FAIL);
	if (trio_multiply_scalar_get(t->scene->light.color,
			brightness, color) != SUCCESS)
		return (ft_error(EINHERIT, "light_parse"));
	return (SUCCESS);
}

static int	light_parse(t_tree *t, char *line)
{
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
	flag = light_parse_helper(t, line);
	if (flag != SUCCESS)
		return (flag);
	t->scene->light.set = true;
	return (SUCCESS);
}
