/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:43:40 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/09 19:58:57 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "libft.h"
#include "miniRT.h"

static int	close_thread(pthread_t *t, size_t i);
static void	*thread_routine(void *data);
static int	thread_init(size_t *i, t_scene *s, t_tree *t);

int	threads_run(t_tree *t)
{
	t->thread_count = 0;
	t->thread_index = 0;
	while (t->thread_count < DEFAULT_THREADS)
	{
		if (pthread_create(&t->threads[t->thread_count],
				NULL, thread_routine, t))
			return (ft_error(EINHERIT, "pthread_create"));
		t->thread_count++;
	}
	return (SUCCESS);
}

static void	*thread_routine(void *data)
{
	t_tree	*t;
	t_scene	s;
	size_t	i;

	t = data;
	ft_memcpy(&s, t->scene, sizeof(t_scene));
	if (thread_init(&i, &s, t) != SUCCESS)
		return ((void *)-1);
	ray_trace(t, &s, i);
	vec_free(&s.objects);
	return (NULL);
}

static int	thread_init(size_t *i, t_scene *s, t_tree *t)
{
	t_vec	*objects;

	objects = NULL;
	if (pthread_mutex_lock(&t->index_lock))
		return (ft_error(EINHERIT, "pthread_mutex_lock"));
	*i = t->thread_index++;
	vec_alloc(&objects, NULL);
	vec_new(objects, t->scene->objects->len, sizeof(t_object));
	if (t->scene->objects->len > 0)
		vec_copy(objects, t->scene->objects);
	s->objects = objects;
	if (pthread_mutex_unlock(&t->index_lock))
		return (ft_error(EINHERIT, "pthread_mutex_unlock"));
	return (SUCCESS);
}

int	threads_join(t_tree *t)
{
	uint32_t	i;
	int			flag;

	flag = SUCCESS;
	i = 0;
	while (i < t->thread_count)
	{
		if (close_thread(&t->threads[i], i) == ERROR)
		{
			flag = ERROR;
			ft_error(EINHERIT, "close_thread");
		}
		i++;
	}
	return (flag);
}

static int	close_thread(pthread_t *t, size_t i)
{
	void		*return_val;
	long		exit_code;

	if (pthread_join(*t, &return_val))
		return (ft_error(EINHERIT, "pthread_join"));
	exit_code = (long)return_val;
	if (exit_code != 0)
	{
		printf("%zu error: %ld\n", i, exit_code);
		return (ft_error(EINHERIT, "thread fail"));
	}
	return (SUCCESS);
}
