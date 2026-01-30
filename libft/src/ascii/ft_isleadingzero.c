/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isleadingzero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:50:54 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/01 16:54:18 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_isleadingzero(const char *nptr)
{
	while (*nptr == '+' || *nptr == '-')
		nptr++;
	if (*nptr == '0')
		return (1);
	return (0);
}
