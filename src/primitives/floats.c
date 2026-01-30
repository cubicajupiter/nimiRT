/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:50:05 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 13:50:06 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

/*
Currently compares all float values by reference to FLT_EQUAL.
However, for very large floats, epsilon may have to scale respectively to maintain precision.
*/
bool   is_float_equal(float a, float b)
{
    if (abs(a - b) < FLT_EPSILON)
        return (true);
    return (false);
}