/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:26:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/10 18:05:58 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include "intersections.h"

//GET RID OF NEGATIVE INTERSECTIONS.
//in fact, DISCARD ALL INTERSECTIONS AFTER HIT

static int	sphere_intersect_get(t_vec *xs, t_sphere *sphere, t_ray ray);
static int	sphere_intersect_math(t_fl *time, t_sphere *sphere, t_ray ray);

int	hit(t_xs **hit, t_vec *xs)
{
	t_xs	*tmp;
	size_t	i;

	if (!xs)
		return (ft_error(EINVAL, "hit"));
	i = 0;
	while (i < xs->len)
	{
		tmp = vec_get(xs, i);
		if (tmp->t > 0.0f)
			break ;
	}
	*hit = tmp;
	return (SUCCESS);
}

static int	sort_ascending(void *a, void *b)
{
	return ((long)*(int *)a - *(int *)b);
}

 // aggregates all intersections found for the ray per object in the world, sorting by t value. 
 // t_scene *world will replace sphere. then loop through all objects in world to find any xs.
int	intersections_get(t_scene *scene, t_ray ray, t_tree *t)
{
	size_t		i;
	t_object	*obj;

	if (!ray)
		return (ft_error(EINVAL, "intersections_get"));
	if (vec_alloc(&scene->xs, t->a_buf) != SUCCESS
		|| vec_new(scene->xs, INIT_XS, sizeof(t_xs)) != SUCCESS)
		return (ft_error(EINHERIT, "intersections_get"));
	i = 0;
	while (i < scene->objects->len)
	{
		obj = vec_get(scene->objects, i);
		intersect_get(scene->xs, obj, ray);
		i++;
	}
	if (vec_sort(scene->xs, sort_ascending) != SUCCESS)
		return (ft_error(EINHERIT, "intersections_get"));
	return (SUCCESS);
}

//will eventually replace sphere with scene, whcih contains sphere
int	intersect_get(t_vec *xs, t_object *obj, t_ray ray)
{
	if (!xs || !obj || !ray)
		return (ft_error(EINVAL, "intersect_get"));
	if (obj->obj_type == SPHERE)
		if (!sphere_intersect_get(xs, obj->sphere, ray))
			return (FALSE);
	return (TRUE);
}

static int	sphere_intersect_get(t_vec *xs, t_sphere *sphere, t_ray ray)
{
	t_ray		ray2;
	t_matrix	inversion;
	t_fl		time[2];
	t_xs		tmp1;
	t_xs		tmp2;

	matrix_invert(inversion, sphere->transform);		//INVERSION
	ray_transform_get(ray2, ray, inversion);		//RAY TRANSFORMATION
	if (sphere_intersect_math(time, sphere, ray2))
	{
		tmp1.t = time[0];
		tmp1.sphere = sphere;
		if (vec_push(xs, &tmp1) != SUCCESS)
			return (ft_error(EINHERIT, "intersect_get"));
		tmp2.t = time[1];
		tmp2.sphere = sphere;
		if (vec_push(xs, &tmp2) != SUCCESS)
			return (ft_error(EINHERIT, "intersect_get"));
	}
	else
		return (FALSE);
	return (TRUE);
}

static int	sphere_intersect_math(t_fl *time, t_sphere *sphere, t_ray ray)
{
	t_fl		discriminant;
	t_tuple		sphere_to_ray;
	t_fl		a;
	t_fl		b;
	t_fl		c;

	tuple_minus_get(sphere_to_ray, ray[ORIGIN], sphere->center); //distance between origin of ray and center of sphere
	vector_dot(&a, ray[DIRECTION], ray[DIRECTION]);  //dot products comparing vectors (both size and angle)
	vector_dot(&b, ray[DIRECTION], sphere_to_ray);
	b *= 2.0f;
	vector_dot(&c, sphere_to_ray, sphere_to_ray);
	c -= 1.0f;	//SPHERE RADIUS SUBTRACTED FROM C HERE (defaults to 1 for test)
	discriminant = (b * b) - (4.0f * a * c);
	if (discriminant < 0.0f)
		return (FALSE);
	time[0] = (-b - sqrtf(discriminant)) / (2.0f * a);
	time[1] = (-b + sqrtf(discriminant)) / (2.0f * a);
	return (TRUE);
}
