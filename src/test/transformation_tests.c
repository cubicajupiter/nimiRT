/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_tests.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:18:37 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/05 17:32:33 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	translation_test(void)
{
	t_matrix	transform;
	t_matrix	inversion;
	t_tuple		point_a;
	t_tuple		point_b;
	t_tuple		point_c;
	t_tuple		vector_a;
	t_tuple		vector_b;

	printf("Translation of points (regular then inverted back to original)\n");
	translation(transform, 5, -3, 2);
	matrix_print(transform);
	point_new(point_a, -3, 4, 5);
	matrix_tuple_multiply(point_b, transform, point_a);
	tuple_print(point_a);
	tuple_print(point_b);
	matrix_invert(inversion, transform);
	matrix_tuple_multiply(point_c, inversion, point_b);
	tuple_print(point_c);
	printf("\n");
	printf("Translation of vectors (no change)\n");
	vector_new(vector_a, -3, 4, 5);
	matrix_tuple_multiply(vector_b, transform, vector_a);
	tuple_print(vector_a);
	tuple_print(vector_b);
}

void	scaling_test(void)
{
	t_matrix	transform;
	t_matrix	inversion;
	t_tuple		point_a;
	t_tuple		point_b;
	t_tuple		point_c;
	t_tuple		point_d;
	t_tuple		vector_a;
	t_tuple		vector_b;

	printf("Scaling of both points and vectors\n");
	scaling(transform, 2, 3, 4);
	matrix_print(transform);
	point_new(point_a, -4, 6, 8);
	matrix_tuple_multiply(point_b, transform, point_a);
	tuple_print(point_a);
	tuple_print(point_b);
	vector_new(vector_a, -4, 6, 8);
	matrix_tuple_multiply(vector_b, transform, vector_a);
	tuple_print(vector_a);
	tuple_print(vector_b);
	matrix_invert(inversion, transform);
	matrix_tuple_multiply(vector_b, inversion, vector_a);
	tuple_print(vector_b);
	printf("\n");
	printf("Reflecting with a negative scale value\n");
	scaling(transform, -1, 1, 1);
	matrix_print(transform);
	point_new(point_c, 2, 3, 4);
	matrix_tuple_multiply(point_d, transform, point_c);
	tuple_print(point_c);
	tuple_print(point_d);
}

void	rotation_test(void)
{
	t_matrix	eighth;
	t_matrix	quarter;
	t_matrix	inversion;
	t_tuple		point_a;
	t_tuple		point_b;
	t_tuple		point_c;
	t_tuple		point_d;

	printf("Rotating points n number of radians\n");
	point_new(point_a, 0, 0, 1);
	rotation_y(eighth, PI / 4);
	rotation_y(quarter, PI / 2);
	matrix_tuple_multiply(point_b, eighth, point_a);
	matrix_tuple_multiply(point_c, quarter, point_a);
	tuple_print(point_a);
	matrix_print(eighth);
	tuple_print(point_b);
	matrix_print(quarter);
	tuple_print(point_c);
	matrix_invert(inversion, eighth);
	matrix_tuple_multiply(point_d, inversion, point_b);
	tuple_print(point_d);
}

void	shearing_test(void)
{
	t_matrix	shear;
	t_tuple		point_a;
	t_tuple		point_b;

	printf("Applying shear transformation to points\n");
	point_new(point_a, 2, 3, 4);
	tuple_print(point_a);
	shearing(shear, (float []){1, 0, 0, 0, 0, 0});
	matrix_tuple_multiply(point_b, shear, point_a);
	tuple_print(point_b);
	shearing(shear, (float []){0, 1, 0, 0, 0, 0});
	matrix_tuple_multiply(point_b, shear, point_a);
	tuple_print(point_b);
	shearing(shear, (float []){0, 0, 1, 0, 0, 0});
	matrix_tuple_multiply(point_b, shear, point_a);
	tuple_print(point_b);
	shearing(shear, (float []){0, 0, 0, 1, 0, 0});
	matrix_tuple_multiply(point_b, shear, point_a);
	tuple_print(point_b);
	shearing(shear, (float []){0, 0, 0, 0, 1, 0});
	matrix_tuple_multiply(point_b, shear, point_a);
	tuple_print(point_b);
	shearing(shear, (float []){0, 0, 0, 0, 0, 1});
	matrix_tuple_multiply(point_b, shear, point_a);
	tuple_print(point_b);
}

void	chaining_test(void)
{
	t_matrix	rotate;
	t_matrix	scale;
	t_matrix	translate;
	t_matrix	chain;
	t_matrix	subchain;
	t_tuple		point_a;
	t_tuple		point_b;
	t_tuple		point_c;
	t_tuple		point_d;
	t_tuple		point_e;

	printf("Applying transformations one-by-one\n");
	point_new(point_a, 1, 0, 1);
	tuple_print(point_a);
	rotation_x(rotate, PI / 2);
	scaling(scale, 5, 5, 5);
	translation(translate, 10, 5, 7);
	matrix_tuple_multiply(point_b, rotate, point_a);
	tuple_print(point_b);
	matrix_tuple_multiply(point_c, scale, point_b);
	tuple_print(point_c);
	matrix_tuple_multiply(point_d, translate, point_c);
	tuple_print(point_d);
	printf("\n");
	printf("OR chaining transformations together\n");
	matrix_multiply(subchain, translate, scale);
	matrix_multiply(chain, subchain, rotate);
	matrix_tuple_multiply(point_e, chain, point_a);
	tuple_print(point_e);
}

int	transformation_test(void)
{
	translation_test();
	printf("\n");
	scaling_test();
	printf("\n");
	rotation_test();
	printf("\n");
	shearing_test();
	printf("\n");
	chaining_test();
	// printf("\n");
	// clock_test();
	return (SUCCESS);
}
