/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_destroyers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:21:50 by thblack-          #+#    #+#             */
/*   Updated: 2025/11/04 19:38:33 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	vec_data_free(t_vec *src)
{
	if (!src)
		return ;
	if (src->arena || !src->data)
	{
		vec_set(src, NULL, 0, 0);
		return ;
	}
	free(src->data);
	src->data = NULL;
	src->capacity = 0;
	src->len = 0;
}

int	vec_reset(t_vec *src)
{
	if (!src)
		return (FAIL);
	if (src->data && !src->arena)
		free(src->data);
	vec_set(src, NULL, 0, 0);
	return (SUCCESS);
}

void	vec_free(t_vec **src)
{
	t_vec	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	if (temp->data && !temp->arena)
	{
		free(temp->data);
		temp->data = NULL;
	}
	if (!temp->arena)
		free(temp);
	*src = NULL;
}
