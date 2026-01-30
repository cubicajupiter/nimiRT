/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:33:14 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 16:33:04 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

int scale_vector(tuple new, const float scalar, tuple vector)
{
    new[X] = vector[X] * scalar;
    new[Y] = vector[Y] * scalar;
    new[Z] = vector[Z] * scalar;
    new[X] = vector[X] * scalar;
    return (0);
}

int get_magnitude(float *magn, const tuple vec)
 {
    *magn = sqrt(vec[X] * vec[X] + vec[Y] * vec[Y] + vec[Z] * vec[Z]);
    return (0);
 }

int normalise_vector(tuple new, tuple vector)
{
    float       magnitude;

    get_magnitude(&magnitude, vector);
    new[X] = vector[X] / magnitude;
    new[Y] = vector[Y] / magnitude;
    new[Z] = vector[Z] / magnitude;
    return (0);
}

/*
Dot product calculates the angle between two vectors (e.g. as a ray bounces off the surface of an object).
It is actually the cosine of the angle between two unit vectors.
*/
int dot_product(float *dot, tuple a, tuple b)
{
    *dot = a[X] * b[X] + a[Y] * b[Y] + a[Z] * b[Z] + a[W] * b[W];
    return (0);
}

int cross_product(tuple new, tuple a, tuple b)
{
    new[X] = a[Y] * b[Z] - a[Z] * b[Y];
    new[Y] = a[Z] * b[X] - a[X] * b[Z];
    new[Z] = a[X] * b[Y] - a[Y] * b[X];
    return (0);
}