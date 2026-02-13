/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:58:54 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 17:01:14 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	debug(t_tree *t, t_run_mode mode)
{
	if (mode == INPUT_DEBUG)
		if (scene_data_print(t) != SUCCESS)
			return (ft_error(EINHERIT, "debug_actions"));
	return (SUCCESS);
}
