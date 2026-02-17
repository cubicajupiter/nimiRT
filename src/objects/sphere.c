/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:22:36 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/17 11:00:01 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

static int	sphere_intersect_math(t_fl *time, t_sphere *sphere, t_ray ray);

int	sphere_new(t_object **dst, t_trio pos, t_fl radius, t_tree *t)
{
	t_sphere	*sphere;
	t_object	object;
	t_object	*tmp;

	if (!pos || !t)
		return (ft_error(EINVAL, "sphere_new"));
	sphere = NULL;
	if (ft_arena_alloc(t->a_buf, (void **)&sphere, sizeof(t_sphere)) != SUCCESS
		|| ft_memset(&object, 0, sizeof(t_object)) == NULL)
		return (ft_error(EINHERIT, "sphere_new"));
	object.type = SPHERE;
	object.sphere = sphere;
	material_new(&object.material);
	sphere->id = t->scene->objects->len;
	if (ft_dtor(&sphere->radius, radius) != SUCCESS
		|| point_new(sphere->center, 0, 0, 0) != SUCCESS
		|| translation(sphere->transform, pos[X], pos[Y], pos[Z]) != SUCCESS
		|| vec_push(t->scene->objects, &object) != SUCCESS)
		return (ft_error(EINHERIT, "sphere_new"));
	tmp = vec_get(t->scene->objects, sphere->id);
	if (dst)
		*dst = tmp;
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
int	sphere_intersect_get(t_vec *xs, t_object *object, t_ray ray)
{
	t_ray		ray2;
	t_matrix	inversion;
	t_fl		time[2];
	t_xs		tmp1;
	t_xs		tmp2;

	matrix_invert(inversion, object->sphere->transform);
	ray_transform_get(ray2, ray, inversion);
	if (sphere_intersect_math(time, object->sphere, ray2))
	{
		tmp1.t = time[0];
		tmp1.object = object;
		if (vec_push(xs, &tmp1) != SUCCESS)
			return (ft_error(EINHERIT, "intersect_get"));
		tmp2.t = time[1];
		tmp2.object = object;
		if (vec_push(xs, &tmp2) != SUCCESS)
			return (ft_error(EINHERIT, "intersect_get"));
	}
	else
		return (FALSE);
	return (TRUE);
}

// Calculates mathss of intersections. Further reading required to fully
// understand. If discriminant is less than 0 then ray misses the sphere and
// the function returns FALSE.
static int	sphere_intersect_math(t_fl *time, t_sphere *sphere, t_ray ray)
{
	t_fl		discriminant;
	t_tuple		sphere_to_ray;
	t_fl		a;
	t_fl		b;
	t_fl		c;

	tuple_minus_get(sphere_to_ray, ray[ORIGIN], sphere->center);
	vector_dot(&a, ray[DIRECTION], ray[DIRECTION]);
	vector_dot(&b, ray[DIRECTION], sphere_to_ray);
	b *= 2.0f;
	vector_dot(&c, sphere_to_ray, sphere_to_ray);
	c -= 1.0f;
	discriminant = (b * b) - (4.0f * a * c);
	if (discriminant < 0.0f)
		return (FALSE);
	time[0] = (-b - sqrtf(discriminant)) / (2.0f * a);
	time[1] = (-b + sqrtf(discriminant)) / (2.0f * a);
	return (TRUE);
}
