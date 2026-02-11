/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:12:51 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/11 16:19:47 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	parse_line(t_tree *t, char *line)
{
	while (ft_isspace(*line))
		line++;
	if (ft_isupper(*line))
		return (parse_main_vars(t, line));
	else if (ft_islower(*line))
		return (parse_objects(t, line));
	return (SUCCESS); // FIXME: Delete after other functions created
}

int	parse_rt(t_tree *t, char *rt_file)
{
	int		fd;
	char	*line;

	if (!t || !rt_file)
		return (ft_error(EINVAL, "init"));
	(void)t;
	line = NULL;
	fd = open(rt_file, O_RDONLY);
	if (fd < 0)
		return (ft_error(EINHERIT, "program_init"));
	line = gnl(fd);
	while (line)
	{
		if (parse_line(t, line) != SUCCESS)
			return (ft_error(EINHERIT, "init"));
		if (line)
			free(line);
		line = gnl(fd);
	}
	free(line);
	return (SUCCESS);
}
