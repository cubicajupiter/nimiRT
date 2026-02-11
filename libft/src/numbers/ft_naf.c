/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_naf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:38:36 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/11 16:05:01 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

bool	ft_naf(const char *nptr)
{
	while (ft_isspace(*nptr))
		nptr++;
	if (ft_issign(*nptr))
		nptr++;
	if (!ft_isdigit(*nptr) && *nptr != '.')
		return (false);
	while (ft_isdigit(*nptr))
		nptr++;
	if (*nptr == '.')
		nptr++;
	if (ft_isdigit(*nptr))
		return (true);
	return (false);
}
