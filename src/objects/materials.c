/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:49:12 by jvalkama          #+#    #+#             */
/*   Updated: 2026/03/12 11:50:03 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	material_new(t_material *dst)
{
	if (!dst)
		return (ft_error(EINVAL, "material_new"));
	color_new(dst->color, 1, 1, 1);
	dst->ambi_light = 0.1;
	dst->diff_light = 0.9;
	dst->spec_light = 0.9;
	dst->shine = 200.0;
	return (SUCCESS);
}