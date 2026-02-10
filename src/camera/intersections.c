/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:26:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/10 11:52:15 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "intersections.h"

//GET RID OF NEGATIVE INTERSECTIONS.
//in fact, DISCARD ALL INTERSECTIONS AFTER HIT

static int	time_val_get(t_fl *time, t_sphere *sphere, t_ray ray);

int	hit(t_xs **hit, t_xs *xs)
{
	t_xs	*tmp;

	if (!xs)
		return (ft_error(EINVAL, "hit"));
	tmp = xs;
	while (tmp)
	{
		if (tmp->data.t > 0)
		{
			*hit = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}

 // aggregates all intersections found for the ray per object in the world, sorting by t value. 
 // t_scene *world will replace sphere. then loop through all objects in world to find any xs.
int	intersections_get(t_xs **xs, t_sphere sphere, t_ray ray)
{
	t_xs		*new;
	t_xs		*tmp;

	if (!ray)
		return (ft_error(EINVAL, "intersections_get"));
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
	return (SUCCESS);
}

//will eventually replace sphere with scene, whcih contains sphere
int	intersect_get(t_xs *dst, t_sphere *sphere, t_ray ray)
{
	t_fl		time[2];
	t_ray		ray2;
	t_matrix	inverted;

	if (!dst || !sphere || !ray)
		return (ERROR);

	matrix_invert(inverted, sphere->transform);		//INVERSION

	printf("Sphere transform matrix:\n");
	matrix_print(sphere->transform);
	printf("\nInverted Sphere transform matrix:\n"); //NOTE: the signs might be an issue!!
	matrix_print(inverted);

	ray_transform_get(ray2, ray, inverted);		//RAY TRANSFORMATION

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
		dst[0].data.t = time[0];
		dst[0].data.sphere = sphere;
		dst[1].data.t = time[1];
		dst[1].data.sphere = sphere;
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

	tuple_minus_get(sphere_to_ray, ray[ORIGIN], sphere->center); //distance L between origin of ray and center of sphere
	vector_dot(&a, ray[DIRECTION], ray[DIRECTION]);  //dot product between ray's direction vec and L
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