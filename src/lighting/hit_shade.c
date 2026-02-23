/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_shade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:44:31 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/23 12:06:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	hit_shade(t_xs *hit, t_ray ray, t_scene *scene)
{
	if (!hit || !ray || !scene)
		return (ft_error(EINVAL, "hit_shade"));
	if (is_shadowed(hit, scene) == FALSE)
	{
		intersection_compute(hit, ray);
		lighting(hit, &scene->light);
	}
	return (SUCCESS);
}
