/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaining.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:42:06 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/06 12:03:13 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Functions intended for chaining transformations together. matrix_chain3()
* handles 3 transformations, while matrix_chain4() handles 4 but neccessitates
* overwriting the 4th "d" matrix (only 4 variables allowed by the Norm).
* Crucially, the chain functions order the transformations in the order that
* we wish them to occur in the final matrix * tuple calculation, NOT the
* reverse order that we process them with matrix_multiply_get(). */

/* Chain 2 transformations together, a and b, output to dst */
int	chain2_get(t_matrix dst, t_matrix a, t_matrix b)
{
	if (!dst || !a || !b)
		return (ft_error(EINVAL, "matrix_chain3"));
	matrix_multiply_get(dst, b, a);
	return (SUCCESS);
}

/* Chain 2 transformations together, a and b (dst) output to dst */
int	chain2_apply(t_matrix dst, t_matrix a)
{
	t_matrix	b;

	if (!dst || !a)
		return (ft_error(EINVAL, "matrix_chain3"));
	matrix_copy(b, dst);
	matrix_multiply_get(dst, b, a);
	return (SUCCESS);
}

/* Chain 3 transformations together, a, b and c, output to dst */
int	chain3_get(t_matrix dst, t_matrix a, t_matrix b, t_matrix c)
{
	t_matrix	subchain;

	if (!dst || !a || !b || !c)
		return (ft_error(EINVAL, "matrix_chain3"));
	matrix_multiply_get(subchain, c, b);
	matrix_multiply_get(dst, subchain, a);
	return (SUCCESS);
}

/* Chain 3 transformations together, a, b and c (dst) output to dst */
int	chain3_apply(t_matrix dst, t_matrix a, t_matrix b)
{
	t_matrix	subchain;
	t_matrix	c;

	if (!dst || !a || !b)
		return (ft_error(EINVAL, "matrix_chain3"));
	matrix_copy(c, dst);
	matrix_multiply_get(subchain, c, b);
	matrix_multiply_get(dst, subchain, a);
	return (SUCCESS);
}

/* Chain 4 transformations together, a, b and c output to dst which also acts
 * as input d (overwritten)*/
int	chain4_apply(t_matrix dst, t_matrix a, t_matrix b, t_matrix c)
{
	t_matrix	subchain_1;
	t_matrix	subchain_2;
	t_matrix	d;

	if (!dst || !a || !b || !c)
		return (ft_error(EINVAL, "matrix_chain4"));
	matrix_copy(d, dst);
	matrix_multiply_get(subchain_1, d, c);
	matrix_multiply_get(subchain_2, subchain_1, b);
	matrix_multiply_get(dst, subchain_2, a);
	return (SUCCESS);
}
