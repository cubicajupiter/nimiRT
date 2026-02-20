/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:55:32 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/20 12:04:47 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "defines.h"
# include "headers.h"

// Tests
// FIX: Remove before evaluations
int		test_matrix(void);
int		test_rays(t_tree *t);
int		projectile_test(t_tree *t);
int		transformation_test(t_tree *t);
void	test_draw_sphere(t_tree *tree);
int		lighting_test(t_tree *t);
void	sphere_shader_test(t_tree *tree);

// Initialization
int		init(t_tree *t, char *rt_file);
int		rt_parse(t_tree *t, char *rt_file);
int		rt_invalid(char c);
int		main_info_parse(t_tree *t, char *line);
int		objects_parse(t_tree *t, char *line);
int		cylinder_parse(t_object **object, t_tree *t, char *line);
int		color_parse(t_object *object, t_tree *t, char *line);
bool		valid_rt_data(char *line);
bool		valid_01_float(t_fl nbr, char *value);
bool		valid_color(t_trio color, char *value);
int		next_var_get(char **line, int (*increment_beyond_type)(int));
int		ft_atotrio(t_trio dst, const char *nptr);
int		ft_atopoint(t_tuple dst, const char *nptr);
int		ft_atovector(t_tuple dst, const char *nptr);
int		parser_atof(t_fl *nbr, char *line);
int		parser_atoi(int *nbr, char *line);
bool		values_within_limits(t_scene *s);
bool		values_make_sense(t_scene *s);
int		materials_set(t_scene *s);

// Ray Trace
int		ray_trace(t_tree *t);

// Window & Image
int		window_init(mlx_t **window, mlx_image_t **image);
int		window_destroy(mlx_t *window, mlx_image_t *image);
int		canvas_put(mlx_image_t *image, t_trio color);
int		pixel_put(mlx_image_t *image, t_uint x, t_uint y, t_trio c);
int		point_put(mlx_image_t *image, t_tuple p, t_trio c);
bool	is_pixel_on_image(t_uint x, t_uint y);
void	commands(void *data);

// Camera
int		camera_compute(t_camera *camera);
int		camera_pixel_size_compute(t_camera *camera);
int		pixel_ray_get(t_ray pixel_ray, t_camera *camera, int x, int y);
int		view_transform_get(t_matrix dst, t_tuple forward_v,
			t_tuple to_p, t_tuple up_v);

// Objects
int		sphere_new(t_object **dst, t_trio pos, t_fl radius, t_tree *t);
int		sphere_hit_get(t_fl *dst, t_object *object, t_ray ray);
int		sphere_transform_set(t_sphere *sphere, t_matrix transformation);
int		sphere_intersect_get(t_vec *xs, t_object *object, t_ray ray);
int		plane_new(t_object **dst, t_trio pos, t_trio vector, t_tree *t);
int		cylinder_new(t_object **dst, t_tuple pos, t_tuple vector, t_tree *t);
int		cylinder_resize(t_object *dst, t_fl radius, t_fl height);

// Rays
int		ray_new(t_ray ray, t_tuple origin, t_tuple direction);
int		position_get(t_tuple pos, t_ray ray, const t_fl time);
int		ray_transform_get(t_ray dst, t_ray src, t_matrix transform);
int		scene_hit_get(t_xs *hit, t_ray ray, t_scene *s);
int		first_intersection_get(t_xs **hit, t_vec *xs);
int		scene_intersections_get(t_vec **dst, t_ray ray, t_tree *t);
int		object_intersections_get(t_vec *xs, t_object *obj, t_ray ray);
int		intersections_sort(t_vec *src);
int		intersection_compute(t_xs *hit, t_ray ray);

// Lighting
void		reflection_ambient(t_material *mat, t_scene *s);
void		reflection_diffuse(t_material *m, t_fl light_dot);
void		reflection_specular(t_material *m, t_light *l, t_fl eye_dot);
int		reflection_get(t_tuple dst, t_tuple in, t_tuple normal);

// Primitives
bool	is_float_equal(t_fl a, t_fl b);
int		float_cmp(t_fl a, t_fl b);
int		ft_dtor(float *dst, int src);
int		ft_rtod(int *dst, float src);

// Matrices
int		matrix_copy(t_matrix dst, t_matrix src);
int		id_matrix(t_matrix dst);
int		matrix_compare(t_matrix a, t_matrix b);
int		matrix_multiply_get(t_matrix dst, t_matrix a, t_matrix b);
int		matrix_tuple_multiply_get(t_tuple dst, t_matrix a, t_tuple b);
int		matrix_multiply_apply(t_matrix dst, t_matrix src);
int		matrix_tuple_multiply_apply(t_tuple dst, t_matrix src);
int		matrix_transpose(t_matrix dst, t_matrix src);
int		matrix_identity_get(t_matrix identity);

// Matrix Invert
int		matrix_invert(t_matrix dst, t_matrix src);
t_fl	cofactor(t_matrix matrix4, t_matrix3 matrix3, int coord[2], int width);
t_fl	minor(t_matrix matrix4, t_matrix3 matrix3, int coord[2], int width);
bool	is_invertible(t_matrix matrix4);

// Transformations
int		translation(t_matrix dst, t_fl x, t_fl y, t_fl z);
int		scaling(t_matrix dst, t_fl x, t_fl y, t_fl z);
int		rotation_x(t_matrix dst, t_fl radians);
int		rotation_y(t_matrix dst, t_fl radians);
int		rotation_z(t_matrix dst, t_fl radians);
int		shearing(t_matrix dst, t_fl src[6]);
int		chain2_get(t_matrix dst, t_matrix a, t_matrix b);
int		chain2_apply(t_matrix dst, t_matrix a);
int		chain3_get(t_matrix dst, t_matrix a, t_matrix b, t_matrix c);
int		chain3_apply(t_matrix dst, t_matrix a, t_matrix b);
int		chain4_apply(t_matrix dst, t_matrix a, t_matrix b, t_matrix c);

// Lighting
int		point_light_new(t_light *dst, t_tuple position, t_trio intensity);
int		normal_sphere_get(t_tuple dst, t_sphere *sphere, t_tuple point);
int		material_default(t_material *dst);
int		lighting(t_xs *hit, t_light *light);

// Tuples
int		point_new(t_tuple tuple, float x, float y, float z);
int		vector_new(t_tuple tuple, float x, float y, float z);
int		is_tuple_equal(t_tuple a, t_tuple b);
int		vector_negate(t_tuple dst, t_tuple src);
int		tuple_copy(t_tuple dst, t_tuple src);

// Basic
int		tuple_add_get(t_tuple new, t_tuple const a, const t_tuple b);
int		tuple_add_apply(t_tuple dst, const t_tuple increment);
int		tuple_minus_get(t_tuple new, t_tuple a, const t_tuple b);
int		tuple_minus_apply(t_tuple dst, const t_tuple decrement);

// Scale
int		vector_multiply_get(t_tuple new, const float scalar, t_tuple vector);
int		vector_multiply_apply(t_tuple dst, const float scalar);
int		vector_divide_get(t_tuple dst, const float scalar, t_tuple vector);
int		vector_divide_apply(t_tuple dst, const float scalar);

// Normlisation and Products
int		magnitude_get(float *magn, t_tuple vector);
int		normalize_get(t_tuple dst, t_tuple vector);
int		normalize_apply(t_tuple vector);
int		vector_dot(float *dot, t_tuple a, t_tuple b);
int		vector_cross(t_tuple dst, t_tuple a, t_tuple b);

// Color
int		color_new(t_trio c, t_fl r, t_fl g, t_fl b);
int		color_copy(t_trio dst, t_trio src);
int		color_trio_to_uint(uint32_t *color, t_trio c);
int		color_uint_to_trio(t_trio c, int *color);

// Utilities
int		debug(t_tree *t, t_run_mode mode);
int		float_print(t_fl fl);
int		int_print(int nbr);
int		float_formatted_print(char *name, t_fl value);
int		int_formatted_print(char *name, int value);
int		color_print(t_trio src);
int		tuple_print(t_tuple src);
int		matrix_print(t_matrix src);
int		insertion_sort(t_xs **dst, t_xs *head);
int		scene_data_print(t_tree *t);
int		objects_print(t_scene *s);
int		sphere_print(t_sphere *sphere);
int		plane_print(t_plane *plane);
int		cylinder_print(t_cylinder *cylinder);
int		object_material_print(t_material *material);
int		material_print(t_material *m);

// Trios
int		trio_multiply_get(t_trio dst, t_trio a, t_trio b);
int		trio_multiply_apply(t_trio dst, t_trio c);
int		trio_multiply_scalar_get(t_trio dst, t_fl scalar, t_trio src);
int		trio_multiply_scalar_apply(t_trio dst, t_fl scalar);
int		trio_divide_get(t_trio dst, t_trio a, t_trio b);
int		trio_divide_apply(t_trio dst, t_trio c);
int		trio_add_get(t_trio dst, t_trio a, t_trio b);
int		trio_add_apply(t_trio dst, t_trio c);
int		trio_minus_get(t_trio dst, t_trio a, t_trio b);
int		trio_minus_apply(t_trio dst, t_trio c);
int		trio_add3_get(t_trio dst, t_trio a, t_trio b, t_trio c);

// Exit
int		memory_free(t_tree *t);
int		error_exit(int flag, t_tree *t);
int		rt_invalid(char c);
bool		rt_out_of_limits(char *value);
int		ft_error(int code, const char *message);

#endif
