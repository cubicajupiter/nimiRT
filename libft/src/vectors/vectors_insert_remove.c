/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_insert_remove.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:17:15 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/11 16:37:44 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include <stdint.h>

int	vec_insert(t_vec *dst, void *src, size_t index)
{
	size_t	offset;
	size_t	offset_bytes;

	if (!src || !dst || index > dst->len || !dst->data)
		return (ft_liberror(EINVAL, "vec_insert"));
	if (vec_check_and_grow(dst, 1) != SUCCESS)
		return (ft_liberror(EINHERIT, "vec_insert"));
	offset = dst->len - index;
	if (offset > 0)
	{
		if (vec_safe_size(offset, dst->elem_size, &offset_bytes) != SUCCESS)
			return (ft_liberror(EINHERIT, "vec_insert"));
		ft_memmove((uint8_t *)dst->data + (index + 1) * dst->elem_size,
			(uint8_t *)dst->data + index * dst->elem_size, offset_bytes);
	}
	ft_memcpy((uint8_t *)dst->data + index * dst->elem_size, src,
		dst->elem_size);
	dst->len++;
	return (SUCCESS);
}

int	vec_remove(t_vec *src, size_t index)
{
	size_t	offset;
	size_t	offset_bytes;

	if (!src || !src->data || src->elem_size == 0 || src->len == 0
		|| index >= src->len)
		return (ft_liberror(EINVAL, "vec_remove"));
	if (index + 1 >= src->len)
		offset = 0;
	else
		offset = src->len - index - 1;
	if (offset > 0)
	{
		if (vec_safe_size(offset, src->elem_size, &offset_bytes) != SUCCESS)
			return (ft_liberror(EINHERIT, "vec_remove"));
		ft_memmove((uint8_t *)src->data + index * src->elem_size,
			(uint8_t *)src->data + (index + 1) * src->elem_size, offset_bytes);
	}
	src->len--;
	if (src->capacity >= 2 && src->len < src->capacity / 4)
		if (vec_resize(src, src->capacity / 2) != SUCCESS)
			return (ft_liberror(EINHERIT, "vec_remove"));
	return (SUCCESS);
}

int	vec_trim(t_vec *src, size_t index, size_t len)
{
	size_t	offset;
	size_t	bytes;

	if (!src || !src->data || src->elem_size == 0 || src->len == 0
		|| index + len > src->len)
		return (ft_liberror(EINVAL, "vec_trim"));
	if (index + len >= src->len)
		offset = 0;
	else
		offset = src->len - index - len;
	if (offset > 0)
	{
		if (vec_safe_size(offset, src->elem_size, &bytes) != SUCCESS)
			return (ft_liberror(EINHERIT, "vec_trim"));
		ft_memmove((uint8_t *)src->data + index * src->elem_size,
			(uint8_t *)src->data + (index + len) * src->elem_size, bytes);
	}
	src->len -= len;
	if (src->capacity >= 2 && src->len < src->capacity / 4)
		if (vec_resize(src, src->capacity / 2) != SUCCESS)
			return (ft_liberror(EINHERIT, "vec_trim"));
	return (SUCCESS);
}
