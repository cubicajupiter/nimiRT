/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:43:23 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/09 17:31:12 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	sorted_insert(t_xs *insert, t_xs **dst);

int	insertion_sort(t_xs **dst, t_xs *head)
{
	t_xs	*current;
	t_xs	*next;
	t_xs	*sorted;

	sorted = NULL;
	if (head)
	{
		current = head;
		while (current != NULL)
		{
			next = current->next;
			sorted_insert(current, &sorted);
			current = next;
		}
	}
	else
		return (ft_error(EINVAL, "insertion_sort"));
	*dst = sorted;
	return (SUCCESS);
}

static void	sorted_insert(t_xs *insert, t_xs **dst)
{
	t_xs	*tmp;

	if (*dst == NULL || (*dst)->data.t >= insert->data.t)
	{
		insert->next = *dst;
		*dst = insert;
	}
	else
	{
		tmp = *dst;
		while (tmp->next != NULL && tmp->next->data.t < insert->data.t)
			tmp = tmp->next;
		insert->next = tmp->next;
		tmp->next = insert;
	}
}
