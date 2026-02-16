/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:40:02 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 17:08:06 by thblack-         ###   ########.fr       */
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
	if (program_init(t) != SUCCESS
		|| scene_init(t) != SUCCESS
		|| window_and_image_init(t) != SUCCESS)
		return (ft_error(EINHERIT, "init"));
	flag = rt_parse(t, rt_file);
	if (flag == ERROR)
		return (ft_error(EINHERIT, "init"));
	return (flag);
}

static int	program_init(t_tree *t)
{
	if (!t)
		return (ft_error(EINVAL, "program_init"));
	t->a_sys = NULL;
	t->a_buf = NULL;
	if (ft_arena_init(&t->a_sys, BUF_SIZE) != SUCCESS
		|| ft_arena_init(&t->a_buf, BUF_SIZE) != SUCCESS)
		return (ft_error(EINHERIT, "program_init"));
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
	if (ft_arena_alloc(t->a_buf, (void **)&new, sizeof(t_scene)) != SUCCESS
		|| ft_memset(new, 0, sizeof(t_scene)) == NULL
		|| vec_alloc(&objects, t->a_buf) != SUCCESS
		|| vec_new(objects, 0, sizeof(t_object)) != SUCCESS
		|| vec_alloc(&xs, t->a_buf) !=  SUCCESS
		|| vec_new(xs, 0, sizeof(t_xs)) != SUCCESS)
		return (ft_error(EINHERIT, "scene_init"));
	new->objects = objects;
	new->xs = xs;
	t->scene = new;
	return (SUCCESS);
}

static int	window_and_image_init(t_tree *t)
{
	window_init(&t->window, &t->image);
	mlx_loop_hook(t->window, commands, t);
	return (SUCCESS);
}
