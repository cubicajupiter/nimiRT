/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:43:23 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/06 16:21:57 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//static int		quicksort_find_tail(t_xs **tail, t_xs *head);
static void		quicksort_recursion(t_xs *low, t_xs *high);
static t_xs		*quicksort_partition(t_xs *low, t_xs *high);
static void		quicksort_swap(t_xs *a, t_xs *b);

int	quicksort(t_xs *head)
{
	t_xs		*tail;

	if (find_tail(&tail, head) == TRUE)
	{
		quicksort_recursion(head, tail);
		return (SUCCESS);
	}
	else
		return (FAIL);
}

int	find_tail(t_xs **tail, t_xs *head)
{
	if (!head)
		return (ft_error(EINVAL, "find_tail"));
	if (head->next == NULL)
		return (FALSE);
	while (head->next)
	{
		head = head->next;
	}
	*tail = head;
	return (TRUE);
}

static void	quicksort_recursion(t_xs *low, t_xs *high)
{
	t_xs		*pivot;

	if (low != NULL && high != NULL && low != high)
	{
		pivot = quicksort_partition(low, high);
		quicksort_recursion(low, pivot);
		quicksort_recursion(pivot->next, high);
	}
}

static t_xs	*quicksort_partition(t_xs *low, t_xs *high)
{
	t_fl		pivot_val;
	t_xs		*i;
	t_xs		*current;

	pivot_val = high->t;
	i = low;
	current = low;
	while (current != high)
	{
		if (float_cmp(current->t, pivot_val) <= 0)
		{
			if (i == NULL)
				i = low;
			else
				i = i->next;
			quicksort_swap(i, current);
		}
		current = current->next;
	}
	if (i == NULL)
		i = low;
	else
		i = i->next;
	quicksort_swap(i, high);
	return (i);
}

static void	quicksort_swap(t_xs *a, t_xs *b) //swap values instead (t and object)
{
	t_xs	*tmp;

	tmp = a;
	a->t = b->t;
	a->object = b->object;
	b->t = tmp->t;
	b->object = tmp->object;
}
