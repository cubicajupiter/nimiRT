/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:49:11 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/03 11:37:33 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* To contain widely needed definitions and inclusions.
To reduce the risk of conflicting defines.
One shared place for all widely needed defines.
Defines that aren't relevant for the whole project can go in specific header files.
*/

#ifndef DEFINES_H
# define DEFINES_H

# include <stdint.h>

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
# define WIDTH 2000
# define HEIGHT 1600

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
# define ALPHA 0xFF

// Forward declarations of library structs from various headers in headers.h
// typedef __uint32_t	uint32_t;
typedef struct mlx			mlx_t;
typedef struct mlx_image	mlx_image_t;

// Types (custom types allow for easy switching later)
typedef float				t_fl; // Custom float type
typedef uint32_t			t_uint; // Custom uint type
typedef float				t_tuple[4];
typedef float				t_trio[3];
typedef float				t_matrix[4][4];
typedef float				t_matrix2[2][2];
typedef float				t_matrix3[3][3];

// Structs
typedef struct s_tree
{
	mlx_t					*window;
	mlx_image_t				*image;
}							t_tree;

#endif
