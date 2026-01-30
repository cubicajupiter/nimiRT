/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:36:56 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/01 16:39:11 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_strisnum(const char *nptr)
{
	int	flag;

	flag = 0;
	while (*nptr)
	{
		if (ft_isdigit(*nptr))
			flag = 1;
		if (!ft_isnum(*nptr) && !ft_isspace(*nptr))
			return (0);
		nptr++;
	}
	return (flag);
}
