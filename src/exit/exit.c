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

// error_exit()
// General purpose exit function for freeing memory, destroying mutexes and
// printing the error code if it exits. In general error codes are used for
// ERROR failures such as malloc fails or incorrect usage of the API. FAIL
// conditions, such as bad *.rt input do not produce erro codes and so do not
// set errno or get printed separately on exit. Separate prompts for bad *.rt
// input are provided by separate rt_error functions.
int	error_exit(int flag, t_tree *t)
{
	if (flag != INIT_MUTEX_FAIL)
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

// free_and_destroy()
// Called by both error exits and exit from the main loop. This function frees
// memory, destroys mutexes and calls MLX functions to free and destroy window
// and image resources.
int	free_and_destroy(t_tree *t)
{
	if (t)
	{
		if (t->scene->objects && t->scene->objects->len > 0)
			if (plane_free(t->scene->objects) != SUCCESS)
				ft_error(EINHERIT, "memory_free");
		if (t->window && t->image)
			mlx_delete_image(t->window, t->image);
		if (t->window)
			window_destroy(t->window);
		if (t->arena)
			ft_arena_list_free(&t->arena);
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
