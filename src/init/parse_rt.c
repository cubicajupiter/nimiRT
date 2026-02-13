/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:12:51 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 15:14:00 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	line_parse(t_tree *t, char *line)
{
	if (!t || !line)
		return (ft_error(EINVAL, "line_parse"));
	while (ft_isspace(*line))
		line++;
	if (!line)
		return (SUCCESS);
	else if (ft_isupper(*line))
		return (main_info_parse(t, line));
	else if (ft_islower(*line))
		return (objects_parse(t, line));
	else
		return (FAIL);
}

int	rt_parse(t_tree *t, char *rt_file)
{
	int		fd;
	char	*line;

	if (!t || !rt_file)
		return (ft_error(EINVAL, "rt_parse"));
	(void)t;
	line = NULL;
	fd = open(rt_file, O_RDONLY);
	if (fd < 0)
		return (ft_error(EINHERIT, "rt_parse"));
	line = gnl(fd);
	while (line)
	{
		if (line_parse(t, line) != SUCCESS)
			return (ft_error(EINHERIT, "rt_parse"));
		if (line)
			free(line);
		line = gnl(fd);
	}
	free(line);
	scene_data_print(t);
	return (SUCCESS);
}
