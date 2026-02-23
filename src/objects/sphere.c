/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:22:36 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/23 18:06:54 by jvalkama         ###   ########.fr       */
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
	ft_memset(&object, 0, sizeof(t_object));
	if (ft_arena_alloc(t->a_buf, (void **)&sphere, sizeof(t_sphere)) != SUCCESS
		|| ft_memset(&object, 0, sizeof(t_object)) == NULL)
		return (ft_error(EINHERIT, "sphere_new"));
	object.type = SPHERE;
	object.sphere = sphere;
	material_default(&object.material);
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
int	sphere_hit_get(t_fl *dst, t_sphere *sphere, t_ray ray)
{
	t_fl		time[2];
	t_ray		ray2;
	t_matrix	inversion;

	if (!dst || !sphere || !ray)
		return (ft_error(EINVAL, "sphere_hit_get"));
	matrix_invert(inversion, sphere->transform);
	ray_transform_get(ray2, ray, inversion);
	if (sphere_intersect_math(time, sphere, ray))
	{
		if (time[0] > 0.0f && time[1] > 0.0f)
		{
			if (time[0] < time[1])
				*dst = time[0];
			else
				*dst = time[1];
		}
		else if (time[0] > 0.0f)
			*dst = time[0];
		else if (time[1] > 0.0f)
			*dst = time[1];
	}
	else
		return (FALSE);
	return (TRUE);
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
	if (sphere_intersect_math(time, object->sphere, ray))
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

	if (!time || !sphere || !ray)
		return (ft_error(EINVAL, "sphere_intersect_math"));
	tuple_minus_get(sphere_to_ray, ray[ORIGIN], sphere->center);
	vector_dot(&a, ray[DIRECTION], ray[DIRECTION]);
	vector_dot(&b, ray[DIRECTION], sphere_to_ray);
	b *= 2.0f;
	vector_dot(&c, sphere_to_ray, sphere_to_ray);
	// c -= 1.0f;
	// FIXME: Temporarilly changed this constant to the sphere radius but the
	// measurements seem to be funky, too small in relation to the space.
	// Needs further investigation!
	c -= sphere->radius;
	discriminant = (b * b) - (4.0f * a * c);
	if (discriminant < 0.0f)
		return (FALSE);
	time[0] = (-b - sqrtf(discriminant)) / (2.0f * a);
	time[1] = (-b + sqrtf(discriminant)) / (2.0f * a);
	// This next check for time being positive may be a problem for other
	// calculations later, but for now it suits our logic
	if (time[0] < 0.0 && time[1] < 0.0)
		return (FALSE);
	return (TRUE);
}
