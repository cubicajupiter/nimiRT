/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:49:11 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 13:46:31 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* To contain widely needed definitions and inclusions.
To reduce the risk of conflicting defines.
One shared place for all widely needed defines.
Defines that aren't relevant for the whole project can go in specific header files.
*/

#ifndef DEFINES_H
# define DEFINES_H

# include <float.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

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
# define POINT 1
# define VECTOR 0
// TUPLE INDEXES
# define X 0
# define Y 1
# define Z 2
# define W 3

typedef float	tuple[4];

#endif
