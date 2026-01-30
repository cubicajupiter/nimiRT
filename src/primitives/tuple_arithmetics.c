/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_arithmetics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:27:35 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 17:11:36 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	add_tuples(tuple new, tuple const a, const tuple b)
{
	if (!new || !a || !b)
		return (ERROR);
	new[X] = a[X] + b[X];
	new[Y] = a[Y] + b[Y];
	new[Z] = a[Z] + b[Z];
	new[W] = a[W] + b[W];
	return (SUCCESS);
}

int	subract_tuples(tuple new, tuple a, const tuple b)
{
	if (!new || !a || !b)
		return (ERROR);
	new[X] = a[X] - b[X];
	new[Y] = a[Y] - b[Y];
	new[Z] = a[Z] - b[Z];
	new[W] = a[W] - b[W];
	return (SUCCESS);
}