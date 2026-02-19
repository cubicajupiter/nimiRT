/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:41:08 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/18 15:20:32 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	orientation_get(\
t_matrix dst, t_tuple left_v, t_tuple true_up_v, t_tuple forward_v);

/*
- !normalize the UP vector param!
- computes the forward vector by suctracting 'from' from 'to'. normalizes the result
- computes the left vector by taking the cross product of forward and the normalized up vector
- computes the true_up vector by taking the cross product of left and forward.
- with left, true_up and forward vectors, constructs a matrix representing the view orientation
- applies a translation to the matrix to move the view.
*/
int	viewport_get(t_matrix dst, t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward_v;
	t_tuple		left_v;
	t_tuple		true_up_v;
	t_matrix	translate;

	tuple_minus_get(forward_v, to, from);
	normalize_apply(forward_v);
	vector_cross(left_v, forward_v, up);
	left_v[W] = 0.0;
	vector_cross(true_up_v, left_v, forward_v);
	true_up_v[W] = 0.0;
	orientation_set(dst, left_v, true_up_v, forward_v);
	translation(translate, -from[X], -from[Y], -from[Z]);
	matrix_multiply_apply(dst, translate);
}

static int	orientation_get(\
t_matrix dst, t_tuple left_v, t_tuple true_up_v, t_tuple forward_v)
{
	t_tuple		neg_forward_v;

	id_matrix(dst);
	vector_negate(neg_forward_v, forward_v);
	dst[0][X] = left_v[X];
	dst[0][Y] = left_v[Y];
	dst[0][Z] = left_v[Z];
	dst[1][X] = true_up_v[X];
	dst[1][Y] = true_up_v[Y];
	dst[1][Z] = true_up_v[Z];
	dst[2][X] = neg_forward_v[X];
	dst[2][Y] = neg_forward_v[Y];
	dst[2][Z] = neg_forward_v[Z];
}