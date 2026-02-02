/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:49:11 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/01 15:28:07 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* To contain widely needed definitions and inclusions.
To reduce the risk of conflicting defines.
One shared place for all widely needed defines.
Defines that aren't relevant for the whole project can go in specific header files.
*/

#ifndef DEFINES_H
# define DEFINES_H

// Retrun Values
// Run checks
# define FAIL 1
# define SUCCESS 0
// Is checks
# define TRUE 1
# define FALSE 0
// Error
# define ERROR -1

//  TUPLES
// TUPLE MODE FLAG
# define POINT 1.0f
# define VECTOR 0.0f
// TUPLE INDEXES
# define X 0
# define Y 1
# define Z 2
# define W 3
// COLOR INDEXES
# define R 0
# define G 1
# define B 2
# define A 3

typedef float   tuple[4];
typedef float   matrix[4][4];
typedef float   matrix2[2][2];
typedef float   matrix3[3][3];

#endif
