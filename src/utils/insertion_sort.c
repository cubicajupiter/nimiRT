/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:43:23 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/09 10:58:08 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	sorted_insert(t_xs *insert, t_xs *dst);

int	insertion_sort(t_xs *dst, t_xs *head)
{
	t_xs	*current;
	t_xs	*next;

	dst = NULL;
	if (head)
	{
		current = head;
		while (current != NULL)
		{
			next = current->next;
			sorted_insert(current, head);
			current = next;
		}
	}
	else
		return (ft_error(EINVAL, "insertion_sort"));
	return (SUCCESS);
}

static void	sorted_insert(t_xs *insert, t_xs *dst)
{
	t_xs	*current;

	if (dst == NULL || dst->data.t >= insert->data.t)
	{
		insert->next = dst;
		dst = insert;
	}
	else
	{
		current = dst; //THIS SHOULD BE ENOUGH TO MODIFY THE VALUES IN PLACE PERMANENTLY
		while (current->next != NULL && current->next->data.t < insert->data.t) {
			current = current->next; printf("loopin2, current t: %f\n", current->next->data.t); }
		insert->next = current->next;
		current->next = insert;
	}
}

