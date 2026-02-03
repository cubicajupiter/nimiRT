/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:53:19 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/03 11:38:29 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int matrix_compare(t_matrix a, t_matrix b)
{
    int     i;
    int     j;

    if (!a || !b)
        return (ft_error(EINVAL, "matrix_compare"));
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

int matrix_multiply(t_matrix dst, t_matrix a, t_matrix b)
{
    float       result;
    int         i;
    int         j;
    
    if (!dst || !a || !b)
        return (ft_error(EINVAL, "matrix_multiply"));
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

int matrix_tuple_multiply(t_tuple dst, t_matrix a, t_tuple b)
{
    float       result;
    int         i;
    int         j;

    if (!dst || !a || !b)
        return (ft_error(EINVAL, "matrix_tuple_multiply"));
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

int matrix_transpose(t_matrix dst, t_matrix src)
{
	t_tuple		row;
	int			i;
	int			j;

    if (!dst || !src)
        return (ft_error(EINVAL, "matrix_transpose"));
	i = 0;
	while (i < 4)
	{
		row = src[i];
		j = 0;
		while (j < 4)
		{
			dst[j][i] = row[j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}