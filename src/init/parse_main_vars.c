/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:13:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/11 16:24:53 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	parse_ambient(t_tree *t, char *line);
// static int	parse_camera(t_tree *t, char *line);
// static int	parse_light(t_tree *t, char *line);

int	parse_main_vars(t_tree *t, char *line)
{
	if (*line == 'A')
		return (parse_ambient(t, line));
	// else if (*line == 'C')
	// 	return (parse_camera(t, line));
	// else if (*line == 'L')
	// 	return (parse_light(t, line));
	return (SUCCESS); // FIXME: Delete after other functions created
}

static int	parse_ambient(t_tree *t, char *line)
{
	int		flag;

	line++;
	while (ft_isspace(*line))
		line++;
	if (!line)
		return (FAIL);
	flag = ft_atof(line, &t->scene->ambient.brightness);
	if (flag != SUCCESS)
		return (flag);
	while (*line && ft_isfloat(*line))
		line++;
	while (ft_isspace(*line))
		line++;
	if (!line)
		return (FAIL);
	return (ft_atotrio(t->scene->ambient.color, line));
}

// static int	parse_camera(t_tree *t, char *line)
// {
// }
//
// static int	parse_light(t_tree *t, char *line)
// {
// }
