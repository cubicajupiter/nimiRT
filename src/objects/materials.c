/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:49:12 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/12 11:11:21 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	material_new(t_material *dst)
{
	//alloc material object
	//dst->shader = alloc shader object
	dst->ambient_light = 0.1;
	dst->diffuse_light = 0.9;
	dst->specular_light = 0.9;
	dst->shininess = 200.0;
}