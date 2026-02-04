/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:50:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/04 17:18:17 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"

int	translation(t_matrix dst, t_trio src)
{
	if (!dst || !src)
		return (ft_error(EINVAL, "translation"));
	id_matrix(dst);
	dst[0][3] = src[0];
	dst[1][3] = src[1];
	dst[2][3] = src[2];
	return (SUCCESS);
}
