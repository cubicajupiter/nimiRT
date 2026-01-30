/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_push_pop_get.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:10:11 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/04 18:38:08 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	vec_resize(t_vec *src, size_t target_cap)
{
	t_vec	new;
	size_t	copy_len;
	size_t	copy_bytes;

	if (!src || src->elem_size == 0)
		return (FAIL);
	if (target_cap == 0)
		return (vec_reset(src));
	new.arena = src->arena;
	if (!vec_new(&new, target_cap, src->elem_size))
		return (FAIL);
	copy_len = src->len;
	if (copy_len > target_cap)
		copy_len = target_cap;
	if (copy_len > 0)
	{
		if (!vec_safe_size(copy_len, src->elem_size, &copy_bytes))
			return (FAIL);
		ft_memcpy(new.data, (uint8_t *)src->data, copy_len * src->elem_size);
	}
	vec_reset(src);
	vec_set(src, new.data, copy_len, new.capacity);
	return (SUCCESS);
}

int	vec_check_and_grow(t_vec *dst, size_t extra)
{
	size_t	target_cap;
	size_t	new_capacity;

	if (!dst)
		return (FAIL);
	if (extra > SIZE_MAX - dst->len)
		return (FAIL);
	target_cap = dst->len + extra;
	if (target_cap <= dst->capacity)
		return (SUCCESS);
	if (dst->capacity != 0)
		new_capacity = dst->capacity;
	else
		new_capacity = 1;
	while (new_capacity < target_cap)
		new_capacity <<= 1;
	return (vec_resize(dst, new_capacity));
}

int	vec_push(t_vec *dst, const void *src)
{
	if (!dst)
		return (FAIL);
	if (dst->elem_size == 0 || !src)
		return (FAIL);
	if (!vec_check_and_grow(dst, 1))
		return (FAIL);
	ft_memcpy((uint8_t *)dst->data + dst->len * dst->elem_size,
		src, dst->elem_size);
	dst->len++;
	return (SUCCESS);
}

int	vec_pop(void *dst, t_vec *src)
{
	size_t	new_capacity;

	if (!src || !dst)
		return (FAIL);
	if (!src->data || src->elem_size == 0 || src->len == 0)
		return (FAIL);
	src->len--;
	ft_memcpy(dst, (uint8_t *)src->data + src->len * src->elem_size,
		src->elem_size);
	if (src->capacity > 1 && src->len <= src->capacity / 4)
	{
		new_capacity = src->capacity / 2;
		if (new_capacity < 1)
			new_capacity = 1;
		if (!vec_resize(src, new_capacity))
			return (FAIL);
	}
	return (SUCCESS);
}

void	*vec_get(t_vec *src, size_t index)
{
	if (!src || !src->data || src->elem_size == 0 || index >= src->len)
		return (NULL);
	else
		return ((uint8_t *)src->data + index * src->elem_size);
}
