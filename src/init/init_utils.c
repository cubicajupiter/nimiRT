/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:20:02 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 11:20:29 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static const char	*next_csv_get(const char *nptr);
static int	ft_atotuple_helper(t_fl *dst, const char *nptr);

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

int	ft_atopoint(t_tuple dst, const char *nptr)
{
	t_fl	xyz[3];

	if (ft_atotuple_helper(xyz, nptr) != SUCCESS)
		return (ft_error(EINHERIT, "ft_atopoint"));
	return (point_new(dst, xyz[X], xyz[Y], xyz[Z]));
}

int	ft_atovector(t_tuple dst, const char *nptr)
{
	t_fl	xyz[3];

	if (ft_atotuple_helper(xyz, nptr) != SUCCESS)
		return (ft_error(EINHERIT, "ft_atopoint"));
	return (vector_new(dst, xyz[X], xyz[Y], xyz[Z]));
}

static int	ft_atotuple_helper(t_fl *dst, const char *nptr)
{
	const char	*ptr[3];

	if (!dst || !nptr)
		return (ft_error(EINVAL, "ft_atotuple"));
	ptr[0] = nptr;
	nptr = next_csv_get(nptr);
	if (!nptr)
		return (rt_invalid((*ptr)[0]));
	ptr[1] = nptr;
	nptr = next_csv_get(nptr);
	if (!nptr)
		return (rt_invalid((*ptr)[1]));
	ptr[2] = nptr;
	if (ft_atof(ptr[0], &dst[X]) != SUCCESS
		|| ft_atof(ptr[1], &dst[Y]) != SUCCESS
		|| ft_atof(ptr[2], &dst[Z]) != SUCCESS)
		return (ft_error(EINHERIT, "ft_atotuple"));
	return (SUCCESS);
}

int	ft_atotrio(t_trio dst, const char *nptr)
{
	const char	*ptr[3];
	int			color[3];

	if (!dst || !nptr)
		return (ft_error(EINVAL, "ft_atotrio"));
	ptr[0] = nptr;
	nptr = next_csv_get(nptr);
	if (!nptr)
		return (rt_invalid((*ptr)[0]));
	ptr[1] = nptr;
	nptr = next_csv_get(nptr);
	if (!nptr)
		return (rt_invalid((*ptr)[0]));
	ptr[2] = nptr;
	if (ft_atoi(ptr[0], &color[R]) != SUCCESS
		|| ft_atoi(ptr[1], &color[G]) != SUCCESS
		|| ft_atoi(ptr[2], &color[B]) != SUCCESS)
		return (ft_error(EINHERIT, "ft_atotrio"));
	return (color_uint_to_trio(dst, color));
}

static const char	*next_csv_get(const char *nptr)
{
	while (*nptr && ft_isfloat(*nptr))
	{
		nptr++;
		if (*nptr == ',' && ft_isfloat(nptr[1]))
			return (nptr + 1);
	}
	return (NULL);
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

