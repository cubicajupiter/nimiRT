/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:24:11 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/24 14:55:50 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

// static int	cylinder_intersect_math(t_fl *time, t_cylinder *cylinder, t_ray ray);

int	cylinder_new(t_object **dst, t_tuple pos, t_tuple vector, t_tree *t)
{
	t_cylinder	*cylinder;
	t_object	object;
	t_object	*tmp;

	if (!pos || !vector || !t)
		return (ft_error(EINVAL, "cylinder_new"));
	cylinder = NULL;
	if (ft_arena_alloc(t->a_buf, (void **)&cylinder,
			sizeof(t_cylinder)) != SUCCESS
		|| ft_memset(&object, 0, sizeof(t_object)) == NULL)
		return (ft_error(EINHERIT, "cylinder_new"));
	object.type = CYLINDER;
	object.id = t->scene->objects->len;
	object.cylinder = cylinder;
	material_default(&object.material);
	if (vector_new(cylinder->axis, vector[X], vector[Y], vector[Z]) != SUCCESS
		|| point_new(cylinder->center, 0, 0, 0) != SUCCESS
		|| translation(cylinder->transform, pos[X], pos[Y], pos[Z]) != SUCCESS
		|| vec_push(t->scene->objects, &object) != SUCCESS)
		return (ft_error(EINHERIT, "cylinder_new"));
	tmp = vec_get(t->scene->objects, object.id);
	if (dst)
		*dst = tmp;
	return (SUCCESS);
}

// THE CYLINDER VERSION FOR GETTING NORMALS.
int	cylinder_normal_get(t_tuple dst, t_cylinder *cylinder, t_tuple point)
{
	t_tuple		obj_point;
	t_tuple		obj_normal;

	if (!dst || !cylinder || !point)
		return (ft_error(EINVAL, "normal_cylinder_get"));
	normal_object_point_get(obj_point, cylinder->transform, point);
	vector_new(obj_normal, obj_point[X], 0.0, obj_point[Z]);
	normal_worldvector_get(dst, cylinder->transform, obj_normal);
	normalize_apply(dst);
	return (SUCCESS);
}

// Inverts the cylinder transform matrix and multiplies the result with the ray,
// then runs cylinder_intersect_math() fetching the two intersections (always
// two even if ray is tangential to edge of cylinder).
int	cylinder_hit_get(t_fl *dst, t_cylinder *cylinder, t_ray ray)
{
	t_fl		time[2];
	t_fl		cylinder_ends[2];
	t_ray		ray2;
	t_matrix	inversion;

	if (!dst || !cylinder || !ray)
		return (ft_error(EINVAL, "cylinder_hit_get"));
	matrix_invert(inversion, cylinder->transform);
	ray_transform_get(ray2, ray, inversion);
	if (cylinder_intersect_math(time, cylinder, ray2))
	// if (cylinder_intersect_math(time, cylinder, ray))
	{
		cylinder_ends[0] = ray[ORIGIN][Y] + (time[0] * ray[DIRECTION][Y]);
		cylinder_ends[1] = ray[ORIGIN][Y] + (time[1] * ray[DIRECTION][Y]);
		if (cylinder_ends[0] < -cylinder->height / 2.0 
			|| cylinder_ends[0] > cylinder->height / 2.0)
			time[0] = -1.0f;
		if (cylinder_ends[1] < -cylinder->height / 2.0 
			|| cylinder_ends[1] > cylinder->height / 2.0)
			time[1] = -1.0f;
		return (closest_forward_hit_get(dst, time));
	}
	return (FALSE);
}

// Calculates mathss of intersections. Further reading required to fully
// understand. If discriminant is less than 0 then ray misses the cylinder and
// the function returns FALSE.
int	cylinder_intersect_math(t_fl *time, t_cylinder *cylinder, t_ray ray)
{
	t_fl		discriminant;
	t_fl		a;
	t_fl		b;
	t_fl		c;

	if (!time || !cylinder || !ray)
		return (ft_error(EINVAL, "cylinder_intersect_math"));
	a = (ray[DIRECTION][X] * ray[DIRECTION][X])
		+ (ray[DIRECTION][Z] * ray[DIRECTION][Z]);
	if (is_float_equal(a, 0.0))
		return (FALSE);
	b = (2.0 * ray[ORIGIN][X] * ray[DIRECTION][X])
		+ (2.0 * ray[ORIGIN][Z]* ray[DIRECTION][Z]);
	c = (ray[ORIGIN][X] * ray [ORIGIN][X])
		+ (ray[ORIGIN][Z] * ray[ORIGIN][Z])
		// NOTE: Not sure about this line of code, as before with sphere, need to include radius. Previously this was a constant -1.0
		- (cylinder->radius * cylinder->radius);
	discriminant = (b * b) - (4.0f * a * c);
	if (discriminant < 0.0f)
		return (FALSE);
	time[0] = (-b - sqrt(discriminant)) / (2 * a);
	time[1] = (-b + sqrt(discriminant)) / (2 * a);
	return (TRUE);
}
