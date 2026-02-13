/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:49:11 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/13 11:25:47 by jvalkama         ###   ########.fr       */
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
typedef t_fl			t_tuple[4];
typedef t_fl			t_trio[3];
typedef t_fl			t_matrix[4][4];
typedef t_fl			t_matrix2[2][2];
typedef t_fl			t_matrix3[3][3];
typedef t_tuple			t_ray[2];
typedef t_fl			t_cylinder[4];
typedef t_fl			t_plane[2];

typedef enum e_obj		t_obj;

typedef struct s_tree		t_tree;
typedef struct s_scene		t_scene;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_ambient	t_ambient;
typedef struct s_sphere		t_sphere;
typedef struct s_intersect	t_intersect;
typedef struct s_xs			t_xs;
typedef struct s_material	t_material;
typedef struct s_shader		t_shader;

enum	e_obj
{
	SPHERE,
	CYLINDER,
	PLANE,
};

// Structs
// Input, filled with data from the *.rt file or assumptions
typedef struct	s_input
{
	t_fl				amb_ratio;
	t_trio				amb_color;
	t_tuple				cam_point;
	t_tuple				cam_vector;
	int					cam_fov;
	t_tuple				lig_point;
	t_fl				lig_ratio;
	t_trio				lig_color;
}						t_input;

// Tree, used to pass around all the data we need to create the image
typedef struct	s_tree
{
	mlx_t				*window;
	mlx_image_t			*image;
	t_arena				*a_sys;
	t_arena				*a_buf;
	t_scene				*scene;
}						t_tree;

// Scene, the lighting, viewpoint, objects and intersections from both camera
// and light rays
typedef struct	s_camera
{
	t_ray				ray;
	int					fov;
}						t_camera;

// typedef struct	s_light
// {
// 	t_tuple				point;
// 	t_fl				brightness;
// 	// t_trio			color; // Bonus feature
// }						t_light;

typedef struct	s_light
{
	t_tuple				pos;
	t_trio				intensity;
}						light;

typedef struct	s_ambient
{
	t_fl				brightness;
	t_trio				color;
}						t_ambient;

typedef struct	s_scene
{
	t_camera			camera;
	t_light				light;
	t_ambient			ambient;
	t_vec				*objects;
	t_vec				*xs;
}						t_scene;

typedef struct	s_shader
{
	t_trio				ambi_refl;
	t_trio				diff_refl;
	t_trio				spec_refl;
	t_trio				combined;
	t_trio				eff_color;
}						t_shader;

typedef struct	s_material
{
	t_shader			shader;
	t_trio				color;
	t_fl				shine;
	t_fl				ambi_light;
	t_fl				diff_light;
	t_fl				spec_light;
}						t_material;

typedef struct	s_object
{
	t_obj				obj_type;
	union {
		t_sphere		*sphere;
		t_cylinder		*cylinder;
		t_plane			*plane;
	};
	t_material			material;
	// t_???			texture;
}						t_object;



typedef struct s_xs
{
	t_object			*object;
	t_fl				t;
}						t_xs;

typedef struct	s_sphere
{
	size_t				id;
	t_tuple				center;
	t_fl				radius;
	t_matrix			transform;
}						t_sphere;

#endif
