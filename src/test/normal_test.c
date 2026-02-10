/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:46:14 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/10 16:46:22 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	normal_tests(void)
{
	printf("\n[ NORMALS ]\n");
	t_sphere	s;
	t_tuple		point;

	sphere_new(&s, 0);
	point_new(s.center, 0.0, 0.0, 0.0);
	point_new(point, 1, 0, 0);

	t_tuple		normal;
	normal_sphere_get(normal, &s, point);
	tuple_print(normal);

	printf("\n");

	point_new(point, 0, 1, 0);
	normal_sphere_get(normal, &s, point);
	tuple_print(normal);

	printf("\n");

	point_new(point, 0, 0, 1);
	normal_sphere_get(normal, &s, point);
	tuple_print(normal);

	printf("\n");

	point_new(point, 0, 0, 1);
	normal_sphere_get(normal, &s, point);
	tuple_print(normal);

	printf("\n");

	point_new(point, sqrtf(3)/3, sqrtf(3)/3, sqrtf(3)/3);
	normal_sphere_get(normal, &s, point);
	tuple_print(normal);

	printf("\n");

	t_tuple	*normalized = &normal;
	normalize_apply(*normalized);
	normal_sphere_get(normal, &s, point);
	tuple_print(normal);
	tuple_print(*normalized);

	printf("\n");



	printf("\n[ TRANSFORMING NORMALS ]\n");
	//set_transform();


	return 0;
}
