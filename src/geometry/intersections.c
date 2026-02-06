/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:26:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/06 10:52:30 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "intersections.h"

//GET RID OF NEGATIVE INTERSECTIONS.
//in fact, DISCARD ALL INTERSECTIONS AFTER HIT

static int	dotproducts_get(t_tuple dot_ps, const t_sphere *const sphere, t_ray ray);

int	hit(t_xs *hit, t_xs *intersections)
{
	int		first;	//FIND SMALLEST POSITIVE T

	first = 0;
	if (first)
		*hit = intersections[first];
	return (SUCCESS);
}

// int	intersect_aggregate(t_xs *xs, t_scene *world) //just aggregates all intersections found per a ray in the world, sorting by t value.
// {
// 	t_xs	current;

// 	current = world->intersections;
// 	while (current)
// 	{
// 		current = current->next;
		
// 	}
// }

//will eventually replace sphere with scene, whcih contains sphere: have object-type specific func calls then
int	intersect_get(t_xs *dst, const t_sphere *const sphere, t_ray ray)
{
	t_trio		dot_ps;

	if (!dst || !sphere || !ray)
		return (ERROR);
	if (dotproducts_get(dot_ps, sphere, ray))
	{
		dst->count = 2;
		dst->xsect[0] = (-dot_ps[SECOND] - sqrtf(dot_ps[DISCR])) / (2 * dot_ps[FIRST]);
		dst->xsect[1] = (-dot_ps[SECOND] + sqrtf(dot_ps[DISCR])) / (2 * dot_ps[FIRST]);
		//dst->object = ;
	}
	else
	{
		dst->count = 0;
		dst->xsect[0] = 0.0;
		dst->xsect[1] = 0.0;
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