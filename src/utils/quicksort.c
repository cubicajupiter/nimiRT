/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:43:23 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/06 14:26:35 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int		find_tail(t_xs **tail, t_xs *head);
static void		quicksort_recursion(t_xs *low, t_xs *high);
static t_xs		*partition(t_xs *low, t_xs *high);
static void		swap(t_xs *a, t_xs *b);

void	quicksort(t_xs **head)
{
	t_xs		*tail;

	if (find_tail(&tail, *head) == TRUE)
	{
		quicksort_recursion(tail, head);
		return (SUCCESS);
	}
	else
		return (FAIL);
}

static int	find_tail(t_xs **tail, t_xs *head)
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
		pivot = partition(low, high);
		quicksort_recursion(low, pivot);
		quicksort_recursion(pivot->next, high);
	}
}

static t_xs	*partition(t_xs *low, t_xs *high)
{
	t_fl		pivot_val;
	t_xs		*i;
	t_xs		*current;

	pivot_val = high->t[0];
	i = low;
	current = low;
	while (current != high)
	{
		if (float_cmp(current->t[0], pivot_val) <= 0)
		{
			if (i == NULL)
				i = low;
			else
				i = i->next;
			swap(i, current);
		}
		current = current->next;
	}
	if (i == NULL)
		i = low;
	else
		i = i->next;
	swap(i, high);
	return (i);
}

static void	swap(t_xs *a, t_xs *b)
{
	t_xs	*tmp;

	tmp = a;
	*a = *b;
	*b = *tmp;
}
