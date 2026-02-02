/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:53:19 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/02 11:35:04 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int matrix_compare(matrix a, matrix b)
{
    int     i;
    int     j;

    if (!a || !b)
        return (ERROR);
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (is_float_equal(a[i][j], b[i][j]) == false)
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE);
}

int matrix_multiply(matrix dst, matrix a, matrix b)
{
    float       result;
    int         i;
    int         j;
    
    if (!dst || !a || !b)
        return (ERROR);
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            result = 0.0;
            result += a[i][0] * b[0][j];
            result += a[i][1] * b[1][j];
            result += a[i][2] * b[2][j];
            result += a[i][3] * b[3][j];
            dst[i][j] = result;
            j++;
        }
        i++;
    }
    return (SUCCESS);
}

int matrix_tuple_multiply(tuple dst, matrix a, tuple b)
{
    float       result;
    int         i;
    int         j;

    if (!dst || !a || !b)
        return (ERROR);
    i = 0;
    while (i < 4)
    {
        j = 0;
        result = 0.0;
        while (j < 4)
        {
            result += a[i][j] * b[j];
            j++;
        }
        dst[i] = result;
        i++;
    }
    return (SUCCESS);
}
