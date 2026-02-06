/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:26:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/06 14:34:12 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "intersections.h"

//GET RID OF NEGATIVE INTERSECTIONS.
//in fact, DISCARD ALL INTERSECTIONS AFTER HIT

static int	dotproducts_get(t_tuple dot_ps, const t_sphere *const sphere, t_ray ray);

int	hit(t_xs *hit, t_xs *intersections)
{
	t_xs		first;	//FIND SMALLEST POSITIVE T

	if (intersections_get(first, ))
		*hit = first;
	return (SUCCESS);
}

 // aggregates all intersections found for the ray per object in the world, sorting by t value. 
 // t_scene *world will replace sphere. then loop through all objects in world to find any xs.
int	intersections_get(t_xs *xs, t_sphere sphere, t_ray ray)
{
	t_xs		new;
	t_fl		smallest_positive;
	
	if (!ray) //only ray is checked here. xs can be NULL. sphere will be changed to WORLD at some point.
		return (ft_error(EINVAL, "intersections_get"));
	while (intersect_get(&new, &sphere, ray)) //once sphere is replaced with world, the loop should become embedded: while object {while intersect{}}
	{	
		if (xs == NULL)
		{
			*xs = new;
			xs->next = NULL;
		}
		else
			xs->next = &new;
		xs = xs->next;
	}
	quicksort(&xs);
	return (SUCCESS);
}

//will eventually replace sphere with scene, whcih contains sphere: have object-type specific func calls then
int	intersect_get(t_xs *dst, const t_sphere *const sphere, t_ray ray)
{
	t_trio		dot_ps;

	if (!dst || !sphere || !ray)
		return (ERROR);
	if (dotproducts_get(dot_ps, sphere, ray))
	{
		dst->count = 2;
		dst->t[0] = (-dot_ps[SECOND] - sqrtf(dot_ps[DISCR])) / (2 * dot_ps[FIRST]);
		dst->t[1] = (-dot_ps[SECOND] + sqrtf(dot_ps[DISCR])) / (2 * dot_ps[FIRST]);
		//dst->object = ;
	}
	else
	{
		dst->count = 0;
		dst->t[0] = 0.0;
		dst->t[1] = 0.0;
		//dst->object = ;
		return (FALSE);
	}
	return (TRUE);
}

static int	dotproducts_get(t_tuple dot_ps, const t_sphere *const sphere, t_ray ray)
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
	dot_ps[FIRST] = a;
	dot_ps[SECOND] = b;
	dot_ps[DISCR] = discriminant;
	return (TRUE);
}