/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:13:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 16:46:35 by thblack-         ###   ########.fr       */
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
	if (next_var_get(&line, NULL) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = parser_atof(&t->scene->ambient.brightness, line);
	if (flag != SUCCESS)
		return (flag);
	if (next_var_get(&line, ft_isfloat) != SUCCESS || !*line)
		return (rt_invalid(*line));
	flag = ft_atotrio(t->scene->ambient.color, line);
	return (flag);
}

static int	camera_parse(t_tree *t, char *line)
{
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
	flag = parser_atoi(&t->scene->camera.fov, line);
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
	return (flag);
}
