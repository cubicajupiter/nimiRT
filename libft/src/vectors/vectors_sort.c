/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:21:01 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/27 14:09:02 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static bool	vec_issort(const t_vec *src, int (*f)(void *, void *))
{
	size_t	i;

	i = 0;
	while (i < src->len - 1)
	{
		if (f(src->data + i * src->elem_size,
				src->data + (i + 1) * src->elem_size) > 0)
			return (false);
		i++;
	}
	return (true);
}

static void	vec_sort_swap(t_vec *src, void *temp, size_t a_index,
		size_t b_index)
{
	ft_memcpy(temp, src->data + a_index * src->elem_size, src->elem_size);
	ft_memcpy(src->data + a_index * src->elem_size,
		src->data + b_index * src->elem_size, src->elem_size);
	ft_memcpy(src->data + b_index * src->elem_size, temp, src->elem_size);
}

int	vec_sort(t_vec *src, int (*f)(void *, void *))
{
	size_t	i;
	void	*temp;

	i = 0;
	if (!src || !src->data || src->elem_size == 0 || src->len == 0 || !f)
		return (-1);
	temp = malloc(sizeof(src->elem_size));
	if (!temp)
		return (-1);
	while (vec_issort(src, f) == false)
	{
		while (i < src->len - 1)
		{
			if (f(src->data + i * src->elem_size,
					src->data + (i + 1) * src->elem_size) > 0)
				vec_sort_swap(src, temp, i, i + 1);
			i++;
		}
	}
	free(temp);
	return (1);
}
