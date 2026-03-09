/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:40:02 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 17:20:35 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "libft.h"
#include "miniRT.h"

static int	program_init(t_tree *t);
static int	scene_init(t_tree *t);
static int	window_and_image_init(t_tree *t);

int	init(t_tree *t, char *rt_file)
{
	int	flag;

	if (!t || !rt_file)
		return (ft_error(EINVAL, "init"));
	if (pthread_mutex_init(&t->index_lock, NULL))
	{
		ft_error(EINHERIT, "pthread_mutex_init");
		return (MUTEX_FAIL);
	}
	if (program_init(t) != SUCCESS
		|| scene_init(t) != SUCCESS
		|| window_and_image_init(t) != SUCCESS)
		return (ft_error(EINHERIT, "init"));
	flag = rt_parse(t, rt_file);
	if (flag == ERROR)
		return (ft_error(EINHERIT, "init"));
	if (flag == FAIL
		|| !values_within_limits(t->scene)
		|| !values_make_sense(t->scene))
		return (FAIL);
	if (materials_set(t->scene) != SUCCESS)
		return (ft_error(EINHERIT, "init"));
	return (SUCCESS);
}

static int	program_init(t_tree *t)
{
	if (!t)
		return (ft_error(EINVAL, "program_init"));
	t->arena = NULL;
	t->image = NULL;
	t->window = NULL;
	t->scene = NULL;
	t->threads = NULL;
	if (ft_arena_init(&t->arena, BUF_SIZE) != SUCCESS
		|| ft_arena_alloc(t->arena, (void **)&t->threads,
			sizeof(pthread_t) * DEFAULT_THREADS) != SUCCESS)
		return (ft_error(EINVAL, "program_init"));
	return (SUCCESS);
}

static int	scene_init(t_tree *t)
{
	t_scene	*new;
	t_vec	*objects;
	t_vec	*xs;

	if (!t)
		return (ft_error(EINVAL, "scene_init"));
	new = NULL;
	objects = NULL;
	xs = NULL;
	if (ft_arena_alloc(t->arena, (void **)&new, sizeof(t_scene)) != SUCCESS
		|| ft_memset(new, 0, sizeof(t_scene)) == NULL
		|| vec_alloc(&objects, t->arena) != SUCCESS
		|| vec_new(objects, 0, sizeof(t_object)) != SUCCESS
		|| vec_alloc(&xs, t->arena) != SUCCESS
		|| vec_new(xs, 0, sizeof(t_xs)) != SUCCESS)
		return (ft_error(EINHERIT, "scene_init"));
	new->objects = objects;
	new->xs = xs;
	t->scene = new;
	return (SUCCESS);
}

static int	window_and_image_init(t_tree *t)
{
	if (window_init(&t->window, &t->image) != SUCCESS)
		return (ft_error(EINHERIT, "window_and_image_init"));
	mlx_loop_hook(t->window, commands, t);
	return (SUCCESS);
}
