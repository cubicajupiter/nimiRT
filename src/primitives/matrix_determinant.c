/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:21:44 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/03 18:54:37 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	determinant2x2(t_fl *det, t_matrix2 matrix)
{
    printf("determinant in 2x2 fore logic: %f\n", *det);
	*det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    printf("determinant in 2x2 after logic: %f\n", *det);
}

void	determinant(t_fl *det, t_matrix3 matrix3, t_matrix matrix4, int width)
{
    int		column;

	column = 0;
	while (column < width)
	{
        if (width == 4)
            *det += matrix4[0][column] * cofactor(matrix4, NULL, (int []){0, column}, width);
        else if (width == 3)
            *det += matrix3[0][column] * cofactor(NULL, matrix3, (int []){0, column}, width);
        column++;
	}
}