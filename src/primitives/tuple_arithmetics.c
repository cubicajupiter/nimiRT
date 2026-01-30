/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_arithmetics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:27:35 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 15:33:37 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

int add_tuples(tuple new, tuple a, const tuple b)
{
    new[X] = a[X] + b[X];
    new[Y] = a[Y] + b[Y];
    new[Z] = a[Z] + b[Z];
    new[W] = a[W] + b[W];
    return (0);
}

int subract_tuples(tuple new, tuple a, const tuple b)
{
    new[X] = a[X] - b[X];
    new[Y] = a[Y] - b[Y];
    new[Z] = a[Z] - b[Z];
    new[W] = a[W] - b[W];
    return (0);
}