/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 10:09:22 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/01 10:12:19 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "messages.h"

static int	mode_prompt(void);

int	mode_parse(t_run_mode *mode, char *flag)
{
	if (!mode || !flag)
		return (ft_error(EINVAL, "mode_parse"));
	if (flag[0] != '-' || !flag[1])
		return (mode_prompt());
	if (flag[1] == 'i')
		*mode = INPUT_DEBUG;
	else if (flag[1] == 'f')
		*mode = FULL_DEBUG;
	else
		return (mode_prompt());
	return (SUCCESS);
}

static int	mode_prompt(void)
{
	ft_putendl_fd("Error\n", 2);
	ft_putendl_fd(MSG_MODE_PROMPT, 2);
	return (1);
}
