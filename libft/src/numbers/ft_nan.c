/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 13:39:22 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/11 16:05:37 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

bool	ft_nan(const char *nptr)
{
	while (ft_isspace(*nptr))
		nptr++;
	if (ft_issign(*nptr))
		nptr++;
	if (ft_isdigit(*nptr))
		return (true);
	return (false);
}
