/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:38:40 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/02 11:04:38 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	color_new(trio c, float r, float g, float b)
{
	if (!c)
		return (ft_error(EINVAL, "color_new"));
	c[R] = r;
	c[G] = g;
	c[B] = b;
	return (SUCCESS);
}
