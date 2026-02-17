/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sensible_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:55:16 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 14:59:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	values_make_sense(t_scene *s)
{
	if (!s)
		return (false);
	// TODO: Check other non-sensical scenarios
	return (true);
}
