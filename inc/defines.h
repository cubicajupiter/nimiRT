/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:49:11 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/02 11:04:29 by thblack-         ###   ########.fr       */
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

// Window & Image
# define WIDTH 400
# define HEIGHT 300

// Tuples
// Tuple Mode Flag
# define POINT 1.0f
# define VECTOR 0.0f
// Tuple Indexes
# define X 0
# define Y 1
# define Z 2
# define W 3
// Color Indexes
# define R 0
# define G 1
# define B 2
// # define A 3 Possibly not needed? Had a look for alpha and transparency and
// it doesn't seem to be used in the RTC book.

typedef float   tuple[4];
typedef float   trio[3];
typedef float   matrix[4][4];
typedef float   matrix2[2][2];
typedef float   matrix3[3][3];

typedef struct mlx			mlx_t;
typedef struct mlx_image	mlx_image_t;

typedef struct	s_tree
{
	mlx_t		*window;
	mlx_image_t	*image;
}	t_tree;

#endif
