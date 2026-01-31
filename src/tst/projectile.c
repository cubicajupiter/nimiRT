/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:42:04 by thblack-          #+#    #+#             */
/*   Updated: 2026/01/31 17:43:04 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

typedef struct s_env
{
    tuple   gravity;
    tuple   wind;
}   t_env;

typedef struct s_proj
{
    tuple   position;
    tuple   velocity;
}   t_proj;

#include <unistd.h>

int tick(t_proj *ball, t_env world)
{
    tuple   accelleration;

    if (tuple_incr(ball->position, ball->velocity) != SUCCESS
        || tuple_add(accelleration, world.gravity, world.wind) != SUCCESS
        || tuple_incr(ball->velocity, accelleration) != SUCCESS)
        return (ERROR);
    tuple_print(ball->position);
    tuple_print(ball->velocity);
    usleep(50000);
    return (SUCCESS);
}

int throw(void)
{
    t_env   world;
    t_proj  ball;

    //  Input values for gravity and wind on this world
    if (vector_new(world.gravity, 0, -0.1, 0) != SUCCESS
        || vector_new(world.wind, -0.01, 0, 0) != SUCCESS)
    {
        printf("World creation failed\n");
        return (ERROR);
    }
    // Input values for the starting position and velocity of the ball
    if (point_new(ball.position, 0, 1, 0) != SUCCESS
        || vector_new(ball.velocity, 1, 1, 0) != SUCCESS
        || normalize_apply(ball.velocity) != SUCCESS)
    {
        printf("Ball creation failed\n");
        return (ERROR);
    }
    printf("Throwing the ball...\n");
    tuple_print(ball.position);
    tuple_print(ball.velocity);
    while (ball.position[Y] > 0)
        tick(&ball, world);
    printf("Impact!\n");
    return (SUCCESS);
}
