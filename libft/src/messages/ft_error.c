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

void	ft_error(void)
{
	ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
	exit(EXIT_FAILURE);
}
