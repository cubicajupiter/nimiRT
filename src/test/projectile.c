/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:42:04 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/06 11:59:54 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

typedef struct s_env
{
	t_tuple	gravity;
	t_tuple	wind;
}			t_env;

typedef struct s_proj
{
	t_tuple	position;
	t_tuple	velocity;
}			t_proj;

#include <unistd.h>

int	tick(t_tree *t, t_proj *ball, t_env world)
{
	t_tuple	accelleration;
	t_uint	x;
	t_uint	y;

	if (tuple_add_apply(ball->position, ball->velocity) != SUCCESS
		|| tuple_add_get(accelleration, world.gravity, world.wind) != SUCCESS
		|| tuple_add_apply(ball->velocity, accelleration) != SUCCESS)
		return (ERROR);
	(void)t;
	x = ball->position[X] * 30;
	y = HEIGHT - (ball->position[Y] * 30);
	pixel_put(t->image, x, y, (t_trio){1, 0, 0});
	tuple_print(ball->position);
	printf(" ");
	tuple_print(ball->velocity);
	printf("\n");
	// usleep(20000);
	return (SUCCESS);
}

int	throw(t_tree * t)
{
	t_env	world;
	t_proj	ball;

	canvas_put(t->image, (t_trio){0, 0, 0});
	//  Input values for gravity and wind on this world
	if (vector_new(world.gravity, 0, -0.012, 0) != SUCCESS
		|| vector_new(world.wind, -0.01, 0, 0) != SUCCESS)
	{
		printf("World creation failed\n");
		return (ERROR);
	}
	// Input values for the starting position and velocity of the ball
	if (point_new(ball.position, 0, 20, 0) != SUCCESS
		|| vector_new(ball.velocity, 1, 1, 0) != SUCCESS
		|| normalize_apply(ball.velocity) != SUCCESS)
	{
		printf("Ball creation failed\n");
		return (ERROR);
	}
	printf("Throwing the ball...\n");
	tuple_print(ball.position);
	printf(" ");
	tuple_print(ball.velocity);
	printf("\n");
	while (ball.position[Y] > 0)
		tick(t, &ball, world);
	printf("Impact!\n");
	mlx_put_string(t->window, "miniRT: point and vector ball test", 20, 20);
	return (SUCCESS);
}

int	projectile_test(t_tree *t)
{
	window_init(&t->window, &t->image);
	mlx_loop_hook(t->window, commands, t);
	throw(t);
	mlx_loop(t->window);
	window_destroy(t->window, t->image);
	return (SUCCESS);
}
