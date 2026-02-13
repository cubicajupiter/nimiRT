/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:12:51 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 17:21:00 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "messages.h"

static int	line_parse(t_tree *t, char *line);
static int	rt_parse_exit(int fd, char *line, int flag);

int	rt_parse(t_tree *t, char *rt_file)
{
	int		fd;
	char	*line;
	int		flag;

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
		flag = line_parse(t, line);
		if (flag != SUCCESS)
			return (rt_parse_exit(fd, line, flag));
		if (line)
			free(line);
		line = gnl(fd);
	}
	free(line);
	if (close(fd) < 0)
		return (ft_error(EINHERIT, "rt_parse"));
	return (SUCCESS);
}

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

static int	rt_parse_exit(int fd, char *line, int flag)
{
	if (line)
		free(line);
	if (close(fd) < 0)
		return (ft_error(EINHERIT, "rt_parse_exit"));
	if (flag == FAIL)
		return (FAIL);
	return (ft_error(EINHERIT, "rt_parse"));
}

int	rt_invalid(char c)
{
	ft_putendl_fd("Error\n", 2);
	if (c)
	{
		ft_putstr_fd("Syntax error near '", 2);
		ft_putchar_fd(c, 2);
		ft_putendl_fd("'\n", 2);
	}
	ft_putendl_fd(MSG_INVALID_RT, 2);
	return (1);
}
