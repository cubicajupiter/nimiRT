/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:22:36 by jvalkama          #+#    #+#             */
/*   Updated: 2026/03/09 18:22:41 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

static inline int	sphere_intersect_math(t_fl *time, t_sphere *sphere,
						t_ray ray);

// sphere_new()
// Creates a new sphere object, malloc'ing space on the arena, and
// and initializing the position and radius of the new sphere to values
// given at input. Confusingly input position is saved to the sphere transform
// matrix and actual position is always zero. Material variables are set to
// default values. All other values are set to zero.
int	sphere_new(t_object **dst, t_trio pos, t_fl radius, t_tree *t)
{
	t_sphere	*sphere;
	t_object	object;

	if (!pos || !t)
		return (ft_error(EINVAL, "sphere_new"));
	sphere = NULL;
	ft_memset(&object, 0, sizeof(t_object));
	if (ft_arena_alloc(t->arena, (void **)&sphere, sizeof(t_sphere)) != SUCCESS
		|| ft_memset(sphere, 0, sizeof(t_sphere)) == NULL
		|| ft_memset(&object, 0, sizeof(t_object)) == NULL)
		return (ft_error(EINHERIT, "sphere_new"));
	object.type = SPHERE;
	object.id = t->scene->objects->len;
	object.sphere = sphere;
	sphere->radius = radius;
	material_default(&object.material);
	if (point_new(sphere->center, 0, 0, 0) != SUCCESS
		|| translation(sphere->transform, pos[X], pos[Y], pos[Z]) != SUCCESS
		|| vec_push(t->scene->objects, &object) != SUCCESS)
		return (ft_error(EINHERIT, "sphere_new"));
	if (dst)
		*dst = vec_get(t->scene->objects, object.id);
	return (SUCCESS);
}

int	sphere_normal_get(t_tuple dst, t_sphere *sphere, t_tuple point)
{
	t_tuple		obj_point;
	t_tuple		obj_normal;

	if (!dst || !sphere || !point)
		return (ft_error(EINVAL, "sphere_normal_get"));
	normal_object_point_get(obj_point, sphere->transform, point);
	tuple_minus_get(obj_normal, obj_point, sphere->center);
	normal_scene_vector_get(dst, sphere->transform, obj_normal);
	normalize_apply(dst);
	return (SUCCESS);
}

// int	sphere_transform_set(t_sphere *sphere, t_matrix transformation)
// {
// 	if (!sphere || !transformation)
// 		return (ft_error(EINVAL, "sphere_transform_set"));
// 	matrix_copy(sphere->transform, transformation);
// 	return (SUCCESS);
// }

// Inverts the sphere transform matrix and multiplies the result with the ray,
// then runs sphere_intersect_math() fetching the two intersections (always
// two even if ray is tangential to edge of sphere).
int	sphere_hit_get(t_fl *dst, t_sphere *sphere, t_ray ray)
{
	t_fl		time[2];
	t_ray		ray2;
	t_matrix	inversion;

	if (!dst || !sphere || !ray)
		return (ft_error(EINVAL, "sphere_hit_get"));
	matrix_invert(inversion, sphere->transform);
	ray_transform_get(ray2, ray, inversion);
	if (sphere_intersect_math(time, sphere, ray2))
		return (closest_forward_hit_get(dst, time));
	return (FALSE);
}

// Inverts the sphere transform matrix and multiplies the result with the ray,
// then runs sphere_intersect_math() fetching the two intersections (always
// two even if ray is tangential to edge of sphere).
int	sphere_intersect_get(t_vec *xs, t_object *object, t_ray ray)
{
	t_fl		time[2];
	t_xs		tmp1;
	t_xs		tmp2;
	t_ray		ray2;
	t_matrix	inversion;

	if (!xs || !object || !ray)
		return (ft_error(EINVAL, "sphere_intersect_get"));
	matrix_invert(inversion, object->sphere->transform);
	ray_transform_get(ray2, ray, inversion);
	if (sphere_intersect_math(time, object->sphere, ray2))
	{
		tmp1.t = time[0];
		tmp1.object = object;
		if (vec_push(xs, &tmp1) != SUCCESS)
			return (ft_error(EINHERIT, "sphere_intersect_get"));
		tmp2.t = time[1];
		tmp2.object = object;
		if (vec_push(xs, &tmp2) != SUCCESS)
			return (ft_error(EINHERIT, "sphere_intersect_get"));
	}
	return (FALSE);
}

// Calculates mathss of intersections. Further reading required to fully
// understand. If discriminant is less than 0 then ray misses the sphere and
// the function returns FALSE.
static inline int	sphere_intersect_math(t_fl *time, t_sphere *sphere,
						t_ray ray)
{
	t_fl		discriminant;
	t_tuple		sphere_to_ray;
	t_fl		a;
	t_fl		b;
	t_fl		c;

	if (!time || !sphere || !ray)
		return (ft_error(EINVAL, "sphere_intersect_math"));
	tuple_minus_get(sphere_to_ray, sphere->center, ray[ORIGIN]);
	vector_dot(&a, ray[DIRECTION], ray[DIRECTION]);
	vector_dot(&b, ray[DIRECTION], sphere_to_ray);
	b *= -2.0f;
	vector_dot(&c, sphere_to_ray, sphere_to_ray);
	c -= sphere->radius * sphere->radius;
	// printf("a: %f b: %f c: %f\n", a, b, c);
	discriminant = (b * b) - (4.0f * a * c);
	// printf("dis: %f\n", discriminant);
	if (discriminant < 0.0f)
		return (FALSE);
	time[0] = (-b - sqrtf(discriminant)) / (2.0f * a);
	time[1] = (-b + sqrtf(discriminant)) / (2.0f * a);
	// printf("time[0]: %f time[1]: %f\n", time[0], time[1]);
	if (time[0] < 0.0 && time[1] < 0.0)
		return (FALSE);
	return (TRUE);
}
