/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:08:43 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 17:12:04 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
