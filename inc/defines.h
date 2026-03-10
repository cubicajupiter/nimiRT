/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:49:11 by jvalkama          #+#    #+#             */
/*   Updated: 2026/03/09 19:36:18 by thblack-         ###   ########.fr       */
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
# include "prototypes.h"
# include <pthread.h>
# include <stdatomic.h>

// Window & Image
# define WIDTH 3000
# define HEIGHT 2000

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
# define EPSILON 1e-6
# define OVERPOINT_HEIGHT 1e-2
// # define EPSILON 1e-5
// // NOTE: Was this value, but made bigger to remove spottiness.

// Weighting for Phong lighting components
# define AMBIENT_RATIO 0.1f
# define DIFFUSE_RATIO 0.7f
# define SPECULAR_RATIO 0.2f

// Initial assumed number of intersections per array
# define INIT_XS 4

// PI
# define PI 3.14159

// Lighting
# define EYE 0
# define NORMAL 1

// Multithreading
# ifndef DEFAULT_THREADS
#  define DEFAULT_THREADS 1
# endif

// Error Tracking
# define MUTEX_FAIL 2

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

enum	e_obj_type
{
	SPHERE,
	CYLINDER,
	PLANE,
};

enum	e_run_mode
{
	RELEASE,
	INPUT_DEBUG,
	FULL_DEBUG,
};

// Structs

// Tree, used to pass around all the data we need to create the image
typedef struct s_tree
{
	mlx_t				*window;
	mlx_image_t			*image;
	t_arena				*arena;
	t_scene				*scene;
	pthread_t			*threads;
	pthread_mutex_t		index_lock;
	// pthread_mutex_t		pixel_put_lock;
	size_t				thread_count;
	size_t				thread_index;
}						t_tree;

// Scene, the lighting, viewpoint, objects and intersections from both camera
// and light rays
typedef struct s_camera
{
	t_ray				ray;
	t_fl				half_width;
	t_fl				half_height;
	t_fl				pixel_size;
	t_fl				fov;
	t_matrix			orientation;
	bool				set;
}						t_camera;

typedef struct s_light
{
	t_tuple				point;
	t_trio				color;
	bool				set;
}						t_light;

typedef struct s_ambient
{
	t_trio				color;
	bool				set;
}						t_ambient;

typedef struct s_scene
{
	t_camera			camera;
	t_light				light;
	t_ambient			ambient;
	t_vec				*objects;
	t_vec				*xs;
}						t_scene;

typedef struct s_shader
{
	t_trio				ambi_refl;
	t_trio				diff_refl;
	t_trio				spec_refl;
	t_trio				combined;
	t_trio				eff_color;
}						t_shader;

typedef struct s_material
{
	t_shader			shader;
	t_trio				color;
	t_fl				shine;
	t_fl				ambi_light;
	t_fl				diff_light;
	t_fl				spec_light;
	bool				in_shadow;
}						t_material;

typedef struct s_object
{
	size_t				id;
	t_obj_type			type;
	union
	{
		t_sphere		*sphere;
		t_cylinder		*cylinder;
		t_plane			*plane;
	};
	t_material			material;
}						t_object;

typedef struct s_xs
{
	t_object			*object;
	t_fl				t;
	t_tuple				point;
	t_tuple				over_point;
	t_tuple				camera_vector;
	t_tuple				normal_vector;
	t_tuple				light_vector;
	bool				inside;
}						t_xs;

typedef struct s_sphere
{
	t_tuple				center;
	t_fl				radius;
	t_matrix			transform;
}						t_sphere;

typedef struct s_plane
{
	t_tuple				point;
	t_tuple				vector;
	t_matrix			transform;
	t_tuple				normal;
	atomic_bool			is_normal_set;
	pthread_mutex_t		normal_lock;
}						t_plane;

typedef struct s_cylinder
{
	t_tuple				center;
	t_tuple				axis;
	t_fl				radius;
	t_fl				height;
	t_matrix			transform;
	bool				closed;
}						t_cylinder;

#endif
