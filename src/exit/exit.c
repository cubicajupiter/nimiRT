/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:08:43 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/09 17:29:07 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

static int	plane_free(t_vec *objects);

int	free_and_destroy(t_tree *t)
{
	if (t)
	{
		if (plane_free(t->scene->objects) != SUCCESS)
			ft_error(EINHERIT, "memory_free");
		if (t->window && t->image)
			mlx_delete_image(t->window, t->image);
		if (t->window)
			window_destroy(t->window);
		if (t->arena)
			ft_arena_free(&t->arena);
	}
	if (pthread_mutex_destroy(&t->index_lock))
		ft_error(EINHERIT, "pthread_mutex_destroy");
	return (SUCCESS);
}

static int	plane_free(t_vec *objects)
{
	t_object	*object;
	size_t		i;

	i = 0;
	while (i < objects->len)
	{
		object = vec_get(objects, i++);
		if (object->type == PLANE && object->plane)
			if (pthread_mutex_destroy(&object->plane->normal_lock))
				ft_error(EINHERIT, "pthread_mutex_destroy");
	}
	return (SUCCESS);
}

int	error_exit(int flag, t_tree *t)
{
	if (flag != MUTEX_FAIL)
		free_and_destroy(t);
	if (errno)
	{
		ft_perror();
		return (errno);
	}
	if (flag == FAIL)
		return (EXIT_FAILURE);
	return (ERROR);
}
