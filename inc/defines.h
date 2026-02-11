/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:49:11 by jvalkama          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/02/10 18:00:19 by jvalkama         ###   ########.fr       */
=======
/*   Updated: 2026/02/10 17:22:46 by thblack-         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

/* To contain widely needed definitions and inclusions.
To reduce the risk of conflicting defines.
One shared place for all widely needed defines.
Defines that aren't relevant for the whole project can go in specific header
files.
*/

#ifndef DEFINES_H
# define DEFINES_H

# include <stdint.h>
# include "MLX42.h"
# include "libft.h"

// Window & Image
// # define WIDTH 2000
// # define HEIGHT 1600
# define WIDTH 1000
# define HEIGHT 1000

// Tuples
// Ray data indexes
# define ORIGIN 0
# define DIRECTION 1
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

// Matrix coordinate flags
# define ROW 0
# define COLUMN 1

// Epsilon for float margin of error.
# define EPSILON 1e-5 // NOTE: This margin of error might cause bugs later.

// Initial assumed number of intersections per array
# define INIT_XS 4

// PI
# define PI 3.14159

// Types (custom types allow for easy switching later)
typedef float			t_fl; // Custom float type
typedef uint32_t		t_uint; // Custom uint type
typedef int_fast16_t	t_fastint; // For performance critical things.
typedef float			t_tuple[4];
typedef float			t_trio[3];
typedef float			t_matrix[4][4];
typedef float			t_matrix2[2][2];
typedef float			t_matrix3[3][3];
typedef t_tuple			t_ray[2];
typedef float			t_cylinder[4];
typedef float			t_plane[2];

typedef enum e_obj		t_obj;

typedef struct s_tree		t_tree;
typedef struct s_scene		t_scene;
typedef struct s_sphere		t_sphere;
typedef struct s_intersect	t_intersect;
typedef struct s_xs			t_xs;

enum	e_obj
{
	SPHERE,
	CYLINDER,
	PLANE,
};

// Structs
typedef struct	s_tree
{
	mlx_t				*window;
	mlx_image_t			*image;
	t_arena				*a_sys;
	t_arena				*a_buf;
	t_scene				*scene;
}						t_tree;

typedef struct	s_scene
{
	t_vec				*objects;
	t_vec				*xs;
	//more
}						t_scene;

typedef struct	s_object
{
	t_obj				obj_type;
	union {
		t_sphere		*sphere;
		t_cylinder		*cylinder;
		t_plane			*plane;
	};
}						t_object;

typedef struct s_xs
{
	t_obj				obj_type;
	union {
		t_sphere		*sphere;
		t_cylinder		*cylinder;
		t_plane			*plane;
	};
	t_fl				t;
}						t_xs;

typedef struct	s_sphere
{
	size_t				id; //All spheres have a unique ID number
	t_tuple				center;
	t_fl				radius;
	t_matrix			transform; // Translation, scaling or shearing from its original locaiton
}						t_sphere;
#endif
