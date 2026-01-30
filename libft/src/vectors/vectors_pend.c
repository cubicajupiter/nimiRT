/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_pend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:10:12 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/04 14:59:06 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include <stdint.h>

static int	vec_pend(t_vec *dst, t_vec *src)
{
	if (!dst || !src)
		return (FAIL);
	if (src->len == 0)
		return (SUCCESS);
	if (dst->elem_size == 0 || dst->elem_size != src->elem_size
		|| !src->data || src->elem_size == 0)
		return (FAIL);
	if (!vec_check_and_grow(dst, src->len))
		return (FAIL);
	return (SUCCESS);
}

int	vec_append(t_vec *dst, t_vec *src)
{
	size_t	src_bytes;
	size_t	dst_bytes;

	if (!dst || !src)
		return (FAIL);
	if (!vec_pend(dst, src))
		return (FAIL);
	if (!vec_safe_size(src->len, dst->elem_size, &src_bytes))
		return (FAIL);
	if (!vec_safe_size(src->len, dst->elem_size, &dst_bytes))
		return (FAIL);
	ft_memcpy((uint8_t *)dst->data + dst_bytes,
		(uint8_t *)src->data, src_bytes);
	dst->len += src->len;
	return (SUCCESS);
}

int	vec_prepend(t_vec *dst, t_vec *src)
{
	size_t	src_bytes;
	size_t	dst_bytes;

	if (!dst || !src)
		return (FAIL);
	if (!vec_pend(dst, src))
		return (FAIL);
	if (!vec_safe_size(src->len, dst->elem_size, &src_bytes))
		return (FAIL);
	if (!vec_safe_size(dst->len, dst->elem_size, &dst_bytes))
		return (FAIL);
	if (dst_bytes > 0)
		ft_memmove((uint8_t *)dst->data + src_bytes,
			(uint8_t *)dst->data, dst_bytes);
	ft_memcpy((uint8_t *)dst->data, (uint8_t *)src->data, src_bytes);
	dst->len += src->len;
	return (SUCCESS);
}

int	vec_inpend(t_vec *dst, t_vec *src, size_t after)
{
	size_t	src_bytes;
	size_t	dst_bytes;
	size_t	offset;

	if (!dst || !src)
		return (FAIL);
	if (after > dst->len)
		return (FAIL);
	if (!vec_pend(dst, src))
		return (FAIL);
	if (!vec_safe_size(src->len, dst->elem_size, &src_bytes))
		return (FAIL);
	offset = dst->len - after;
	if (offset > 0)
	{
		if (!vec_safe_size(offset, dst->elem_size, &dst_bytes))
			return (FAIL);
		ft_memmove((uint8_t *)dst->data + (after + src->len) * dst->elem_size,
			(uint8_t *)dst->data + after * dst->elem_size, dst_bytes);
	}
	ft_memcpy((uint8_t *)dst->data + after * dst->elem_size,
		(uint8_t *)src->data, src->len * dst->elem_size);
	dst->len += src->len;
	return (SUCCESS);
}
