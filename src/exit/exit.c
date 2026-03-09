/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:08:43 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/01 11:32:05 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

int	memory_free(t_tree *t)
{
	if (t)
	{
		if (t->window && t->image)
			window_destroy(t->window, t->image);
		if (t->a_sys)
			ft_arena_free(&t->a_sys);
		if (t->a_buf)
			ft_arena_free(&t->a_buf);
	}
	if (pthread_mutex_destroy(&t->index_lock))
		ft_error(EINHERIT, "pthread_mutex_destroy");
	// if (pthread_mutex_destroy(&t->pixel_put_lock))
	// 	ft_error(EINHERIT, "pthread_mutex_destroy");
	return (SUCCESS);
}

int	error_exit(int flag, t_tree *t)
{
	memory_free(t);
	if (errno)
	{
		ft_perror();
		return (errno);
	}
	if (flag == FAIL)
		return (EXIT_FAILURE);
	return (ERROR);
}
