/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_builders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:23:38 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/04 19:47:35 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	vec_alloc(t_vec **dst, t_arena *arena)
{
	t_vec	*new;

	new = NULL;
	if (!dst)
		return (FAIL);
	if (*dst)
		return (SUCCESS);
	if (arena)
		if (!ft_arena_alloc(arena, (void **)&new, sizeof(t_vec)))
			return (vec_exit(*dst));
	if (!arena)
	{
		new = malloc(sizeof(t_vec));
		if (!new)
			return (vec_exit(*dst));
	}
	vec_init(new, 0, 0, arena);
	*dst = new;
	return (SUCCESS);
}

int	vec_new(t_vec *dst, size_t init_len, size_t elem_size)
{
	size_t	bytes;

	if (!dst || elem_size == 0)
		return (FAIL);
	vec_init(dst, init_len, elem_size, dst->arena);
	if (init_len == 0)
		return (SUCCESS);
	if (!vec_safe_size(init_len, elem_size, &bytes))
		return (FAIL);
	if (dst->arena)
		if (!ft_arena_alloc(dst->arena, (void **)&dst->data, bytes))
			return (vec_exit(dst));
	if (!dst->arena)
	{
		dst->data = malloc(bytes);
		if (!dst->data)
			return (vec_exit(dst));
	}
	return (SUCCESS);
}

int	vec_from(t_vec *dst, void *src, size_t len, size_t elem_size)
{
	size_t	bytes;

	if (!src || !dst || elem_size == 0)
		return (FAIL);
	if (len == 0)
		return (vec_new(dst, 0, elem_size));
	if (!vec_safe_size(len, elem_size, &bytes))
		return (FAIL);
	if (!vec_new(dst, len * 2, elem_size))
		return (FAIL);
	ft_memcpy(dst->data, src, bytes);
	dst->len = len;
	return (SUCCESS);
}

int	vec_copy(t_vec *dst, t_vec *src)
{
	size_t	n;
	size_t	dst_cap;
	size_t	bytes;

	if (!dst || !src)
		return (FAIL);
	if (dst == src || dst->elem_size != src->elem_size || dst->elem_size == 0
		|| src->elem_size == 0 || !dst->data || !src->data)
		return (FAIL);
	if (src->len == 0)
		return (SUCCESS);
	n = src->len;
	dst_cap = dst->capacity;
	if (dst->len + n > dst_cap)
		n = dst_cap - dst->len;
	if (!vec_safe_size(n, dst->elem_size, &bytes))
		return (FAIL);
	ft_memcpy((uint8_t *)dst->data + dst->len * dst->elem_size,
		(uint8_t *)src->data, bytes);
	dst->len += n;
	return (SUCCESS);
}
