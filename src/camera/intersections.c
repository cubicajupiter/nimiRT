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

static int	time_val_get(t_fl *time, t_sphere *sphere, t_ray ray);

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
int	intersections_get(t_vec *xs, t_sphere sphere, t_ray ray, t_tree *t)
{
	if (!ray)
		return (ft_error(EINVAL, "intersections_get"));
	xs = NULL;
	if (vec_alloc(&xs, t->a_buf) != SUCCESS
		|| vec_new(xs, INIT_XS, sizeof(t_xs)) != SUCCESS)
		return (ft_error(EINHERIT, "intersections_get"));
	intersect_get(xs, &sphere, ray); //once sphere is replaced with world, the loop should be: while (world_objects) {if intersect_get(){;}}

	size_t	i;
	t_xs	*print;
	i = 0;
	while (i < xs->len)
	{
		print = vec_get(xs, i);
		printf("t: %f\n", print->t);
		i++;
	}
	if (xs->len > 0)
		if (vec_sort(xs, sort_ascending) != SUCCESS)
			return (ft_error(EINHERIT, "intersections_get"));
	i = 0;
	while (i < xs->len)
	{
		print = vec_get(xs, i);
		printf("t: %f\n", print->t);
		i++;
	}
	
	/*
	new = malloc(2 * sizeof(t_xs));	//malloc here so the new intersections persist
	tmp = *xs;
	while (tmp->next)
		tmp = tmp->next;
	if (intersect_get(new, &sphere, ray)) //once sphere is replaced with world, the loop should be: while (world_objects) {if intersect_get(){;}}
	{
		if (tmp == NULL)
		{
			*tmp = new[0];
			tmp->next = &new[1];
			tmp = tmp->next;
		}
		else
		{
			tmp->next = &new[0];
			tmp->next->next = &new[1];
			tmp = tmp->next->next;
		}
	}
	else
		free(new);	// FREE here for now.
	tmp->next = NULL;
	tmp = *xs;
	*xs = NULL;
	insertion_sort(xs, tmp); // sorting by t value.
	// */
	return (SUCCESS);
}

//will eventually replace sphere with scene, whcih contains sphere
int	intersect_get(t_vec *xs, t_sphere *sphere, t_ray ray)
{
	t_fl		time[2];
	t_ray		ray2;
	t_matrix	inversion;
	t_xs		tmp1;
	t_xs		tmp2;

	if (!xs || !sphere || !ray)
		return (ft_error(EINVAL, "intersect_get"));

	matrix_invert(inversion, sphere->transform);		//INVERSION

	printf("Sphere transform matrix:\n");
	matrix_print(sphere->transform);
	printf("\nInverted Sphere transform matrix:\n");
	matrix_print(inversion);

	ray_transform_get(ray2, ray, inversion);		//RAY TRANSFORMATION

	printf("Ray origin:\n");
	tuple_print(ray[ORIGIN]);
	printf("\nRay direction:\n");
	tuple_print(ray[DIRECTION]);

	//normalize_apply(ray2[DIRECTION]);		IN CASE OF SCALING, NO NORMALIZATION NEEDED...

	printf("\nRay2 origin:\n");
	tuple_print(ray2[ORIGIN]);
	printf("\nRay2 direction:\n");
	tuple_print(ray2[DIRECTION]);

	if (time_val_get(time, sphere, ray2))
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

static int	time_val_get(t_fl *time, t_sphere *sphere, t_ray ray)
{
	t_fl		discriminant;
	t_tuple		sphere_to_ray;
	t_fl		a;
	t_fl		b;
	t_fl		c;

	tuple_minus_get(sphere_to_ray, ray[ORIGIN], sphere->center); //distance between origin of ray and center of sphere
	vector_dot(&a, ray[DIRECTION], ray[DIRECTION]);  //dot products comparing vectors (both size and angle)
	vector_dot(&b, ray[DIRECTION], sphere_to_ray);
	b *= 2;
	vector_dot(&c, sphere_to_ray, sphere_to_ray);
	c -= 1;	//SPHERE RADIUS SUBTRACTED FROM C HERE (defaults to 1 for test)
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (FALSE);
	time[0] = (-b - sqrtf(discriminant)) / (2 * a);
	time[1] = (-b + sqrtf(discriminant)) / (2 * a);
	return (TRUE);
}
