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
		return (ft_liberror(EINVAL, "vec_pend"));
	if (src->len == 0)
		return (SUCCESS);
	if (dst->elem_size == 0 || dst->elem_size != src->elem_size
		|| !src->data || src->elem_size == 0)
		return (ft_liberror(EINVAL, "vec_pend"));
	if (vec_check_and_grow(dst, src->len) != SUCCESS)
		return (ft_liberror(EINHERIT, "vec_pend"));
	return (SUCCESS);
}

int	vec_append(t_vec *dst, t_vec *src)
{
	size_t	src_bytes;
	size_t	dst_bytes;

	if (!dst || !src)
		return (ft_liberror(EINVAL, "vec_append"));
	if (vec_pend(dst, src) != SUCCESS
		|| vec_safe_size(src->len, dst->elem_size, &src_bytes) != SUCCESS
		|| vec_safe_size(src->len, dst->elem_size, &dst_bytes) != SUCCESS)
		return (ft_liberror(EINHERIT, "vec_append"));
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
		return (ft_liberror(EINVAL, "vec_prepend"));
	if (vec_pend(dst, src) != SUCCESS
		|| vec_safe_size(src->len, dst->elem_size, &src_bytes) != SUCCESS
		|| vec_safe_size(src->len, dst->elem_size, &dst_bytes) != SUCCESS)
		return (ft_liberror(EINHERIT, "vec_prepend"));
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

	if (!dst || !src || after > dst->len)
		return (ft_liberror(EINVAL, "vec_inpend"));
	if (vec_pend(dst, src) != SUCCESS
		|| vec_safe_size(src->len, dst->elem_size, &src_bytes) != SUCCESS)
		return (ft_liberror(EINHERIT, "vec_inpend"));
	offset = dst->len - after;
	if (offset > 0)
	{
		if (vec_safe_size(offset, dst->elem_size, &dst_bytes) != SUCCESS)
			ft_memmove((uint8_t *)dst->data + (after + src->len) * dst->elem_size,
			(uint8_t *)dst->data + after * dst->elem_size, dst_bytes);
	}
	ft_memcpy((uint8_t *)dst->data + after * dst->elem_size,
		(uint8_t *)src->data, src->len * dst->elem_size);
	dst->len += src->len;
	return (SUCCESS);
}
