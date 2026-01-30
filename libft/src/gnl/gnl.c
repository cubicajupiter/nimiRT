/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:52:38 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/19 22:33:20 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*ft_join_free(char *tmp, char *str)
{
	char	*res;

	if (!tmp && !str)
		return (NULL);
	if (!tmp)
		return (str);
	if (!str)
		return (tmp);
	res = ft_strjoin(tmp, str);
	free(tmp);
	return (res);
}

static char	*ft_find_line(char **heap, char *buffer, char *newline)
{
	char	*line;
	size_t	len;

	*newline = '\0';
	*heap = ft_join_free(*heap, buffer);
	if (!*heap)
		return (NULL);
	*heap = ft_join_free(*heap, "\n");
	if (!*heap)
		return (NULL);
	line = *heap;
	len = ft_strlen(newline + 1);
	ft_memmove(buffer, newline + 1, len + 1);
	return (line);
}

static char	*safe_exit(char *line, char *buffer)
{
	buffer[0] = '\0';
	if (line)
		free(line);
	return (NULL);
}

static char	*handle_eof(char *line)
{
	if (line && *line)
		return (line);
	if (line)
		free(line);
	return (NULL);
}

char	*gnl(int fd)
{
	static char	buffer[BUF_SIZE + 1];
	char		*tmp;
	char		*line;
	ssize_t		size;

	line = ft_strjoin("", "");
	if (fd < 0 || fd >= FD_MAX || BUF_SIZE <= 0 || !line)
		return (safe_exit(line, buffer));
	while (1)
	{
		tmp = ft_strchr(buffer, '\n');
		if (tmp)
			return (ft_find_line(&line, buffer, tmp));
		line = ft_join_free(line, buffer);
		if (!line)
			return (NULL);
		buffer[0] = '\0';
		size = read(fd, buffer, BUF_SIZE);
		if (size < 0)
			return (safe_exit(line, buffer));
		buffer[size] = '\0';
		if (size == 0)
			return (handle_eof(line));
	}
}
