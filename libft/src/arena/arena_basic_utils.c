/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_basic_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:29:36 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/13 15:21:32 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_arena_init(t_arena **arena, size_t capacity)
{
	t_arena	*new;

	if (!arena || capacity == 0)
		return (ft_liberror(EINVAL, "ft_arena_init"));
	if (capacity > (SIZE_MAX / sizeof(uint8_t)))
		return (ft_liberror(ERANGE, "ft_arena_init"));
	new = malloc(sizeof(t_arena));
	if (!new)
		return (ft_liberror(ENOMEM, "ft_arena_init"));
	new->data = malloc(sizeof(uint8_t) * capacity);
	if (!new->data)
	{
		free(new);
		return (ft_liberror(ENOMEM, "ft_arena_init"));
	}
	new->capacity = capacity;
	new->size = 0;
	new->next = NULL;
	*arena = new;
	return (SUCCESS);
}

int	ft_arena_alloc(t_arena *arena, void **ptr, size_t size)
{
	t_arena	*current;
	t_arena	*next;
	size_t	capacity;

	if (!arena || !arena->data || size == 0)
		return (ft_liberror(EINVAL, "ft_arena_alloc"));
	current = arena;
	capacity = size;
	next = NULL;
	while (current->size + size >= current->capacity && current->next)
		current = current->next;
	if (current->size + size > current->capacity)
	{
		current->size = current->capacity;
		if (capacity < ARENA_BUF)
			capacity = ARENA_BUF;
		if (ft_arena_init(&next, capacity) < 0)
			return (ft_liberror(EINHERIT, "ft_arena_alloc"));
		current->next = next;
		current = current->next;
	}
	*ptr = (void *)&current->data[current->size];
	current->size += size;
	return (SUCCESS);
}

int	ft_arena_reset(t_arena *arena)
{
	if (!arena)
		return (ft_liberror(EINVAL, "ft_arena_reset"));
	arena->size = 0;
	return (SUCCESS);
}

int	ft_arena_free(t_arena **arena)
{
	t_arena	*temp;

	if (!arena || !*arena)
		return (ft_liberror(EINVAL, "ft_arena_free"));
	temp = *arena;
	free(temp->data);
	temp->data = NULL;
	free(temp);
	*arena = NULL;
	return (SUCCESS);
}

int	ft_arena_list_free(t_arena **arena)
{
	t_arena	*current;
	t_arena	*next;

	if (!arena)
		return (ft_liberror(EINVAL, "ft_arena_list_free"));
	if (!*arena)
		return (SUCCESS);
	current = *arena;
	while (current)
	{
		next = current->next;
		if (ft_arena_free(&current) < 0)
			return (ft_liberror(EINHERIT, "ft_arena_list_free"));
		current = next;
	}
	*arena = NULL;
	return (SUCCESS);
}
