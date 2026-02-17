/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:20:02 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 13:53:07 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	valid_rt_data(char *line)
{
	while (*line)
	{
		if (!ft_isfloat(*line) && !ft_isspace(*line) && *line != ',')
		{
			rt_invalid(*line);
			return (false);
		}
		line++;
	}
	return (true);
}

int	next_var_get(char **line, int (*increment_beyond_type)(int))
{
	char	*tmp;

	if (!line)
		return (ft_error(EINVAL, "next_var_get"));
	tmp = *line;
	if (increment_beyond_type)
		while (*tmp && (increment_beyond_type(*tmp) || *tmp == ','))
			tmp++;
	while (*tmp && ft_isspace(*tmp))
		tmp++;
	if (!tmp)
		return (FAIL);
	*line = tmp;
	return (SUCCESS);
}

int	parser_atof(t_fl *nbr, char *line)
{
	int	flag;

	if (!nbr || !line)
		return (ft_error(EINVAL, "parser_atoi"));
	flag = ft_atof(line, nbr);
	if (flag == FAIL)
		return (rt_invalid(*line));
	if (flag == ERROR)
		return (ft_error(EINHERIT, "parser_atoi"));
	return (SUCCESS);
}

int	parser_atoi(int	*nbr, char *line)
{
	int	flag;

	if (!nbr || !line)
		return (ft_error(EINVAL, "parser_atoi"));
	flag = ft_atoi(line, nbr);
	if (flag == FAIL)
		return (rt_invalid(*line));
	if (flag == ERROR)
		return (ft_error(EINHERIT, "parser_atoi"));
	return (SUCCESS);
}
