/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:19:03 by thblack-          #+#    #+#             */
/*   Updated: 2025/07/22 11:23:27 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putstr(const char *s)
{
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	count = ft_strlen(s);
	if (write(1, s, count) < 0)
		return (-1);
	return (count);
}
