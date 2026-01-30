/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_func_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:51:33 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/04 15:01:17 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	vec_iter(t_vec *src, void (*f)(void *))
{
	size_t	i;

	i = 0;
	if (!src || !src->data || src->elem_size == 0 || src->len == 0 || !f)
		return (-1);
	while (i < src->len)
		(f)(src->data + src->elem_size * i++);
	return (1);
}

int	vec_map(t_vec *dst, t_vec *src, void (*f)(void *))
{
	if (!src || !dst || dst == src || src->elem_size == 0 || !src->data || !f)
		return (-1);
	if (src->len > dst->capacity)
	{
		if (!src->data)
			if (vec_new(dst, src->len, src->elem_size) < 0)
				return (-1);
		if (src->data)
			if (vec_resize(dst, src->len))
				return (-1);
	}
	if (vec_copy(dst, src) < 0)
		return (-1);
	if (vec_iter(dst, f) < 0)
		return (-1);
	return (1);
}

int	vec_filter(t_vec *dst, t_vec *src, bool (*f)(void *))
{
	size_t	i;

	i = 0;
	if (!src || !dst || dst == src || src->elem_size == 0 || !src->data || !f)
		return (-1);
	while (i < src->len)
	{
		if (f(src->data + i * src->elem_size) == true)
			if (vec_push(dst, src->data + i * src->elem_size) < 0)
				return (-1);
		i++;
	}
	return (1);
}

int	vec_reduce(void *acc, t_vec *src, void (*f)(void *, void *))
{
	size_t	i;

	i = 0;
	if (!acc || !src || src->elem_size == 0 || !src->data || !f)
		return (-1);
	while (i < src->len)
		f(acc, src->data + src->elem_size * i++);
	return (1);
}
