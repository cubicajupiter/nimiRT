/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 09:56:42 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/01 09:58:57 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	access_try(char *path, int mode)
{
	if (access(path, mode) != 0)
		return (FALSE);
	return (TRUE);
}
