/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:38:40 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/02 14:22:49 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	color_new(t_trio c, t_fl r, t_fl g, t_fl b)
{
	if (!c)
		return (ft_error(EINVAL, "color_new"));
	c[R] = r;
	c[G] = g;
	c[B] = b;
	return (SUCCESS);
}
