/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:26:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/09 11:49:04 by jvalkama         ###   ########.fr       */
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
	while (tmp->data.t < 0)
	{
		printf("hit?\n");
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
int	intersections_get(t_xs *xs, t_sphere sphere, t_ray ray)
{
	t_xs		new[2];	//would need to be allocated for changes to persist.
	t_xs		*tmp;

	if (!ray) //only ray is checked here. xs can be NULL. sphere will be changed to WORLD at some point.
		return (ft_error(EINVAL, "intersections_get"));
	tmp = xs;
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
	tmp->next = NULL;
	tmp = xs;
	printf("tmp values: %f	%f	%f	%f	%f	%f	%p\n", tmp->data.t, tmp->next->data.t, tmp->next->next->data.t, tmp->next->next->next->data.t, tmp->next->next->next->next->data.t, tmp->next->next->next->next->next->data.t, tmp->next->next->next->next->next->next);
	//insertion_sort(xs, tmp); // sorting by t value.
	return (SUCCESS);
}

//will eventually replace sphere with scene, whcih contains sphere: have object-type specific func calls then
int	intersect_get(t_xs *dst, t_sphere *sphere, t_ray ray)
{
	t_fl		time[2];

	if (!dst || !sphere || !ray)
		return (ERROR);
	if (time_val_get(time, sphere, ray))
	{
		dst[0].data.t = time[0];
		dst[0].data.sphere = sphere;
		dst[1].data.t = time[1];
		dst[1].data.sphere = sphere;
	}
	else 
	{
		return (FALSE);
	}
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