/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:41:08 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/23 15:49:45 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	orientation_get(\
t_matrix dst, t_tuple left_v, t_tuple true_up_v, t_tuple forward_v);

/*
- !normalize the UP vector param before passing to viewport_get!
- computes the forward vector by suctracting 'from' from 'to'. normalizes the result
- computes the left vector by taking the cross product of forward and the normalized up vector
- computes the true_up vector by taking the cross product of left and forward.
- with left, true_up and forward vectors, constructs a matrix representing the view orientation
- applies a translation to the matrix to move the view.
*/
int	view_transform_get(t_matrix dst, t_tuple from_p, t_tuple forward_v,
						t_tuple up_v)
{
	t_tuple		left_v;
	t_tuple		true_up_v;
	t_matrix	orientation;
	t_matrix	move_scene_translation;

	if (!dst || !from_p || !forward_v || !up_v
		|| from_p[W] < POINT || forward_v[W] > VECTOR || up_v[W] > VECTOR)
		return (ft_error(EINVAL, "view_transform_get"));
	normalize_apply(forward_v);
	normalize_apply(up_v);
	vector_cross(left_v, forward_v, up_v);
	vector_cross(true_up_v, left_v, forward_v);
	orientation_get(orientation, left_v, true_up_v, forward_v);
	// Not sure about these next two lines, example test in book gives different
	// results than the ones produced by these lines
	translation(move_scene_translation, -from_p[X], -from_p[Y], -from_p[Z]);
	matrix_multiply_get(dst, orientation, move_scene_translation);
	return (SUCCESS);
}

/*
	A point of potential optimization.
*/
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
	return (SUCCESS);
}
