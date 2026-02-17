/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:49:12 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/17 17:57:43 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	material_default(t_material *dst)
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
