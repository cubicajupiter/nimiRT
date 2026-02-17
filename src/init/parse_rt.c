/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:12:51 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 13:27:18 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "messages.h"

static int	line_parse(t_tree *t, char *line);
static int	rt_parse_exit(int fd, char *line, int flag);

/*
rt_parse()
A getnextline wrapper that passes lines from the *.rt file to the line_parse()
function which interprets the rt data.
*/
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

/*
line_parse()
Handler for new lines from the *.rt document. Passes the line to separate
parsers for main info (ambient lighting, camera and point light)
distinguished by their upper case characters, and parsers for objects
(spheres, planes and cylinders) distinguished by their lower case characters.
*/
static int	line_parse(t_tree *t, char *line)
{
	if (!t || !line)
		return (ft_error(EINVAL, "line_parse"));
	while (ft_isspace(*line))
		line++;
	if (!*line || *line == '\n')
		return (SUCCESS);
	else if (ft_isupper(*line))
		return (main_info_parse(t, line));
	else if (ft_islower(*line))
		return (objects_parse(t, line));
	else
		return (rt_invalid(*line));
}

/*
rt_parse_exit()
Handles early non-succes exit from the rt parser. Frees the line from gnl and
closes the *.rt file fd, preserving the non-success flag from the parser, which
could be both FAIL for invalid *.rt file and ERROR for a system or input fail.
*/
static int	rt_parse_exit(int fd, char *line, int flag)
{
	if (line)
		free(line);
	if (close(fd) < 0)
		return (ft_error(EINHERIT, "rt_parse_exit"));
	if (flag == ERROR)
		return (ft_error(EINHERIT, "rt_parse"));
	return (FAIL);
}

/*
rt_invlid()
Prints a custom error message letting the user know where an *.rt file might
contain a bad syntax.
*/
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
	return (FAIL);
}
