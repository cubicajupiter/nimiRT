/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:49:12 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/12 14:11:44 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	material_new(t_material *dst)
{
	//alloc material object
	//dst->shader = alloc shader object
	dst->ambi_l = 0.1;
	dst->diff_light = 0.9;
	dst->spec_light = 0.9;
	dst->shine = 200.0;
}