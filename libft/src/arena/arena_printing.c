/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:22:39 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/03 20:08:50 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_print_arena(const t_arena *arena)
{
	if (!arena)
	{
		ft_putendl_fd("arena: (null)", 2);
		return ;
	}
	ft_printf("capacity: %u, size: %u, data ptr: %p, next ptr: %p\n",
		(u_int32_t)arena->capacity, (u_int32_t)arena->size,
		(const void *)arena->data, (const void *)arena->data);
}

void	ft_print_arena_list(const t_arena *arena)
{
	const t_arena	*current;
	int				i;

	if (!arena)
	{
		ft_putendl_fd("arena: (null)", 2);
		return ;
	}
	current = arena;
	i = 1;
	while (current)
	{
		ft_printf("ARENA %d ", i);
		ft_print_arena(current);
		current = current->next;
		i++;
	}
}
