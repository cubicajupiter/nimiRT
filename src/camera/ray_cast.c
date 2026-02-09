/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:30:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/09 20:00:04 by jvalkama         ###   ########.fr       */
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

/*
	Transforming the ray is a substitute to transforming a sphere.
	Whatever transformation you want for a sphere, do the inverse of that transformation to a ray.
*/
int	ray_transform_get(t_ray dst, t_ray src, t_matrix transform)
{
	matrix_tuple_multiply_get(dst[ORIGIN], transform, src[ORIGIN]);
	matrix_tuple_multiply_get(dst[DIRECTION], transform, src[DIRECTION]);
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

	intersections_get(&intersections, s, ray);
	t_xs	*tmp = intersections;
	printf("Sorted intersections\n");
	while (tmp)
	{
		printf("\t %f\n", tmp->data.t);
		tmp = tmp->next;
	}
	printf("\n");

	

	printf("\n[ HITS ]\n");
	t_xs	*h;
	hit(&h, intersections);
	printf("Hit at: %f\n", h->data.t);
	free(intersections->next);



	printf("\n[ TRANSFORMATIONS ]\n");
	t_tuple		p;
	t_tuple		v;
	t_ray		ray1;
	t_ray		ray2;
	t_matrix	transformation;

	printf("Translation:\n");
	point_new(p, 1, 2, 3);
	vector_new(v, 0, 1, 0);
	ray_new(ray1, p, v);
	translation(transformation, 3, 4, 5);
	ray_transform_get(ray2, ray1, transformation);
	tuple_print(ray2[ORIGIN]);
	tuple_print(ray2[DIRECTION]);

	t_ray		ray3;
	t_matrix	transformation2;
	printf("Scaling:\n");
	scaling(transformation2, 2, 3, 4);
	ray_transform_get(ray3, ray1, transformation2);
	tuple_print(ray3[ORIGIN]);
	tuple_print(ray3[DIRECTION]);

	t_matrix	transformation3;
	t_sphere	sphere1;
	sphere_new(&sphere1);
	printf("Sphere's identity matrix:\n");
	matrix_print(sphere1.transform);
	translation(transformation3, 2, 3, 4);
	sphere_transform_set(&sphere1, transformation3);
	printf("Sphere's transform matrix after setting:\n");
	matrix_print(sphere1.transform);
	
	t_tuple		point2;
	t_tuple		vector2;
	t_ray		ray4;
	t_matrix	transformation4;
	t_sphere	sphere2;
	t_xs		intersect[2];
	printf("Intersecting a transformed sphere with a ray:\n");
	point_new(point2, 0, 0, -5);
	vector_new(vector2, 0, 0, 1);
	ray_new(ray4, point2, vector2);
	scaling(transformation4, 2, 2, 2);
	sphere_new(&sphere2);
	sphere_transform_set(&sphere2, transformation4);

	intersect_get(intersect, &sphere2, ray4);
	printf("T1: %f	T2: %f\n", intersect[0].data.t, intersect[1].data.t);	//FIX: These are currently giving garbage values.

	return 0;
}