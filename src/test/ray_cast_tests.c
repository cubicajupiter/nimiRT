
#include "miniRT.h"

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
	t_tuple		center;
	point_new(center, 0.0, 0.0, 0.0);
	point_new(point, 0.0, 0.0, -5.0);
	vector_new(vector, 0.0, 0.0, 1.0);
	ray_new(ray, point, vector);

	sphere_new(&s, center);

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
	sphere_new(&s, center);

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
	t_tuple		point1;
	t_tuple		vector1;
	t_ray		ray1;
	t_ray		ray2;
	t_matrix	transformation;

	printf("Translation:\n");
	point_new(point1, 1, 2, 3);
	vector_new(vector1, 0, 1, 0);
	ray_new(ray1, point1, vector1);
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
	sphere_new(&sphere1, center);
	printf("Sphere's identity matrix:\n");
	matrix_print(sphere1.transform);
	translation(transformation3, 2, 3, 4);
	sphere_transform_set(&sphere1, transformation3);
	printf("Sphere's transform matrix after setting:\n");
	matrix_print(sphere1.transform);
	
	printf("\n[ SCALED RAY INTERSECTION ]\n");
	t_tuple		point2;
	t_tuple		vector2;
	
	t_ray		ray4;
	t_matrix	transformation4;
	t_sphere	sphere2;
	t_xs		intersect[2];
	intersect[0].data.t = 0.0;
	intersect[1].data.t = 0.0;
	printf("Intersecting a transformed sphere with a ray:\n");
	point_new(point2, 0, 0, -5);
	vector_new(vector2, 0, 0, 1);
	ray_new(ray4, point2, vector2);
	scaling(transformation4, 2, 2, 2);
	sphere_new(&sphere2, center);
	sphere_transform_set(&sphere2, transformation4);

	intersect_get(intersect, &sphere2, ray4); // These are now giving either  0 and 0,  or 5 and 5.  Should be  3 and 7!!!!!!!!!!!!!!
	printf("T1: %f	T2: %f\n", intersect[0].data.t, intersect[1].data.t);	

	// printf("\n[ TRANSLATED RAY INTERSECTION (WORKS) ]\n");
	// t_tuple		point3;
	// t_tuple		vector3;
	// t_ray		ray5;
	// t_matrix	transformation5;
	// t_sphere	sphere3;
	// t_xs		intersect2[2];
	// intersect2[0].data.t = 0.0;
	// intersect2[1].data.t = 0.0;
	// point_new(point3, 0, 0, -5);
	// vector_new(vector3, 0, 0, 1);
	// ray_new(ray5, point3, vector3);
	// translation(transformation5, 5, 0, 0);
	// sphere_new(&sphere3);
	// sphere_transform_set(&sphere3, transformation5);

	//intersect_get(intersect2, &sphere3, ray5);
	//printf("T1: %f	T2: %f\n", intersect2[0].data.t, intersect2[1].data.t);

	
	return 0;
}