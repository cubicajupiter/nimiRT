/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atotrio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:20:36 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/11 16:20:43 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static const char	*next_value_get(const char *nptr)
{
	while (*nptr && (ft_isfloat(*nptr) || *nptr == ','))
	{
		nptr++;
		if (*nptr == ',')
			return (nptr + 1);
	}
	return (nptr);
}

int	ft_atotrio(t_trio dst, const char *nptr)
{
	const char	*ptr[3];
	int			color[3];

	if (!dst || !nptr)
		return (ft_error(EINVAL, "ft_atotrio"));
	ptr[0] = nptr;
	nptr = next_value_get(nptr);
	if (!nptr)
		return (FAIL);
	ptr[1] = nptr;
	nptr = next_value_get(nptr);
	if (!nptr)
		return (FAIL);
	ptr[2] = nptr;
	if (ft_atoi(ptr[0], &color[R]) != SUCCESS
		|| ft_atoi(ptr[1], &color[G]) != SUCCESS
		|| ft_atoi(ptr[2], &color[B]) != SUCCESS)
		return (ft_error(EINHERIT, "ft_atotrio"));
	return (color_uint_to_trio(dst, color));
}
