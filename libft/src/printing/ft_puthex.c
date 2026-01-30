/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:09:13 by thblack-          #+#    #+#             */
/*   Updated: 2025/07/22 11:23:14 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_puthex(unsigned long nbr, const char *hex)
{
	int		count;
	int		i;
	char	buffer[16];

	if (nbr < 16)
		return (ft_putchar(hex[nbr]));
	i = 0;
	while (nbr > 0)
	{
		buffer[i++] = hex[nbr % 16];
		nbr /= 16;
	}
	count = i;
	while (i > 0)
	{
		if (!ft_putchar(buffer[--i]))
			return (-1);
	}
	return (count);
}
