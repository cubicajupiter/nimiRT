/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_tests.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:18:37 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/04 17:26:07 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	transformation_test(void)
{
	t_matrix	transform;
	t_tuple		point_a;
	t_tuple		point_b;

	translation(transform, (float []){5, -3, 2});
	point_new(point_a, -3, 4, 5);
	matrix_tuple_multiply(point_b, transform, point_a);
	tuple_print(point_a);
	printf("\n");
	tuple_print(point_b);
	printf("\n");
	return (SUCCESS);
}
