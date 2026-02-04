/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:30:52 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/04 17:47:52 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
    A Ray is an array of 2 tuples: origin and direction
    Origin is a point tuple, and Direction is a vector tuple.
    But it really only becomes an actual ray with position(), which applies time.
*/
int ray_new(t_ray ray, t_tuple origin, t_tuple direction)
{
    int i;

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
int position_get(t_tuple pos, t_ray ray, const t_fl time)
{
    t_tuple     distance;

    vector_multiply_get(distance, time, ray[DIRECTION]);
    tuple_add_get(pos, ray[ORIGIN], distance);
    return (SUCCESS);
}


void    test_rays(void)
{
    t_tuple     point;
    t_tuple     vector;
    t_ray       ray;
    t_fl        time;

    printf("\n[ RAY NEW ]\n");
    point_new(point, 1, 2, 3);
    vector_new(vector, 4, 5, 6);
    ray_new(ray, point, vector);


    
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



    printf("\n[ ]\n");



    printf("\n[ ]\n");



    printf("\n[ ]\n");


    
    printf("\n[ ]\n");
}