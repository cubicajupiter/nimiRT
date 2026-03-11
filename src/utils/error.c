/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:05:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/10 16:04:07 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "messages.h"

int	ft_error(int code, const char *message)
{
	if (code)
		errno = code;
	if (message && *message)
		printf("Error: %s() fail\n", message);
	return (ERROR);
}
