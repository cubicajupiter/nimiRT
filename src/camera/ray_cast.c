/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:30:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/07 17:39:04 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
    A Ray is an array of 2 tuples: origin and direction
    Origin is a point tuple, and Direction is a vector tuple.
    But it really only becomes an actual ray with position(), which applies time.
*/
int	ray_new(t_ray ray, t_tuple origin, t_tuple direction)
{
	int		i;

	if (!origin || !direction)
		return (ft_error(EINVAL, "ray"));
	if (origin[W] != POINT || direction[W] != VECTOR)
		return (ft_error(EINVAL, "ray"));
	i = 0;
	while (i < 4)
	{
		ray[ORIGIN][i] = origin[i];
		ray[DIRECTION][i] = direction[i];
		i++;
	}
	return (SUCCESS);
}

/*
    Position is calculated by applying time to the ray.
    The ray's direction vector is scaled up/down with time to get distance (time can apparently be negative ;) ).
    The distance is added to the ray's origin point to get position pos.
    pos is a point tuple.
*/
int	position_get(t_tuple pos, t_ray ray, const t_fl time)
{
	t_tuple		distance;

	vector_multiply_get(distance, time, ray[DIRECTION]);
	tuple_add_get(pos, ray[ORIGIN], distance);
	return (SUCCESS);
}


int    test_rays(void)
{
	t_tuple		point;
	t_tuple		vector;
	t_ray		ray;
	t_fl		time;

	printf("\n[ RAY NEW ]\n");
	point_new(point, 1, 2, 3);
	vector_new(vector, 4, 5, 6);
	ray_new(ray, point, vector);
	printf("\nRay data:  %f %f %f  -  %f %f %f\n", ray[ORIGIN][0], ray[ORIGIN][1], ray[ORIGIN][2], ray[DIRECTION][0], ray[DIRECTION][1], ray[DIRECTION][2]);


    
	printf("\n[ POSITION GET ]\n");
	time = 3.5;
	point_new(point, 2, 3, 4);
	vector_new(vector, 1, 0, 0);
	ray_new(ray, point, vector);

	position_get(point, ray, time);
	printf("\t%f\t%f\t%f\n", point[X], point[Y], point[Z]);

	position_get(point, ray, 0.0);
	printf("\t%f\t%f\t%f\n", point[X], point[Y], point[Z]);

	position_get(point, ray, 1.0);
	printf("\t%f\t%f\t%f\n", point[X], point[Y], point[Z]);

	position_get(point, ray, -1.0);
	printf("\t%f\t%f\t%f\n", point[X], point[Y], point[Z]);

	position_get(point, ray, 2.5);
	printf("\t%f\t%f\t%f\n", point[X], point[Y], point[Z]);



	printf("\n[ INTERSECTIONS ]\n");
	t_sphere	s;
	t_xs		xs[2];
	point_new(point, 0.0, 0.0, -5.0);
	vector_new(vector, 0.0, 0.0, 1.0);
	ray_new(ray, point, vector);

	sphere_new(&s);
	point_new(s.center, 0.0, 0.0, 0.0);

	intersect_get(xs, &s, ray);
	printf("\nFIRST RAY intersections 0 and 1: %f	%f\n", xs[0].data.t, xs[1].data.t);

	point_new(point, 0.0, 1.0, -5.0);
	vector_new(vector, 0.0, 0.0, 1.0);
	ray_new(ray, point, vector);
	intersect_get(xs, &s, ray);
	printf("\nSECOND RAY intersections 0 and 1: %f	%f\n", xs[0].data.t, xs[1].data.t);

	point_new(point, 0.0, 2.0, -5.0);
	vector_new(vector, 0.0, 0.0, 1.0);
	ray_new(ray, point, vector);
	intersect_get(xs, &s, ray);
	printf("\nTHIRD RAY intersections 0 and 1: %f	%f\n", xs[0].data.t, xs[1].data.t);

	point_new(point, 0.0, 0.0, 0.0);
	vector_new(vector, 0.0, 0.0, 1.0);
	ray_new(ray, point, vector);
	intersect_get(xs, &s, ray);
	printf("\nFOURTH RAY intersections 0 and 1: %f	%f\n", xs[0].data.t, xs[1].data.t);

	point_new(point, 0.0, 0.0, 5.0);
	vector_new(vector, 0.0, 0.0, 1.0);
	ray_new(ray, point, vector);
	intersect_get(xs, &s, ray);
	printf("\nFIFTH RAY intersections 0 and 1: %f	%f\n", xs[0].data.t, xs[1].data.t);



	printf("\n[ TRACKING MULTIPLE INTERSECTIONS ]\n");
	point_new(point, 0.0, 0.0, -2.0);
	vector_new(vector, 0.0, 0.0, 1.0);
	ray_new(ray, point, vector);
	sphere_new(&s);
	point_new(s.center, 0.0, 0.0, 0.0);

	t_xs 	i1;
	t_xs	i2;
	t_xs	i3;
	t_xs	i4;
	i1.data.t = 10.0;

	i1.data.sphere = &s;

	i2.data.t = 13.0;
	i2.data.sphere = &s;

	i3.data.t = -3;
	i3.data.sphere = &s;

	i4.data.t = 2;
	i4.data.sphere = &s;
	i4.next = NULL;

	t_xs	*intersections;
	intersections = &i1;
	intersections->next = &i2;
	intersections->next->next = &i3;
	intersections->next->next->next = &i4;

	printf("Here 7\n");
	intersections_get(intersections, s, ray);
	printf("Here 8\n");
	while (intersections)
	{
		printf("%f	", intersections->data.t);
		intersections = intersections->next;
	}
	printf("\n");
//	tuple_print();
//	matrix_print();



	printf("\n[ HITS ]\n");
	t_xs	h;
	printf("Here 8\n");
	hit(&h, intersections);
	printf("Here 9\n");
    
	printf("\n[ TRANSFORMATIONS ]\n");
    
	return 0;
}