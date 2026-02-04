/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:22:36 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/04 18:48:10 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int sphere_new(t_sphere *dst)
{
    static t_uint   id = 0;

    id++;
    *dst = id;
    return (SUCCESS);
}