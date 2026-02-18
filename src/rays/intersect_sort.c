/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:38:09 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/18 10:56:42 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	intersections_issort(t_vec *src)
{
	t_xs	*xs_a;
	t_xs	*xs_b;
	size_t	i;

	i = 0;
	while (i < src->len - 1)
	{
		xs_a = vec_get(src, i);
		xs_b = vec_get(src, i + 1);
		if (xs_a->t > xs_b->t)
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

int	intersections_sort(t_vec *src)
{
	t_xs	*xs_a;
	t_xs	*xs_b;
	size_t	i;
	void	*temp;

	if (!src || !src->data || src->elem_size == 0 || src->len == 0)
		return (ft_error(EINVAL, "intersect_sort"));
	temp = malloc(sizeof(t_xs));
	if (!temp)
		return (ft_liberror(ENOMEM, "intersect_sort"));
	while (!intersections_issort(src))
	{
		i = 0;
		while (i < src->len - 1)
		{
			xs_a = vec_get(src, i);
			xs_b = vec_get(src, i + 1);
			if (xs_a->t > xs_b->t)
				vec_sort_swap(src, temp, i, i + 1);
			i++;
		}
	}
	free(temp);
	return (SUCCESS);
}
