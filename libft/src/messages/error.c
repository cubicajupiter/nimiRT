/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:47:54 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/01 16:48:53 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_perror(void)
{
	ft_putendl_fd((char *)strerror(errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	ft_liberror(int code, const char *message)
{
	if (code)
		errno = code;
	if (message && *message)
	{
		ft_putstr_fd("Libft error: ", STDERR_FILENO);
		ft_putstr_fd((char *)message, STDERR_FILENO);
		ft_putendl_fd("() fail", STDERR_FILENO);
	}
	return (ERROR);
}
