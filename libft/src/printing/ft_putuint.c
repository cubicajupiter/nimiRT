/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:21:01 by thblack-          #+#    #+#             */
/*   Updated: 2025/07/22 11:21:29 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putuint(unsigned int n)
{
	int		count;
	int		i;
	char	*buffer;

	if (n < 10)
		return (ft_putchar(n + '0'));
	buffer = malloc(sizeof(char) * ft_digitcount(n, 10));
	if (!buffer)
		return (-1);
	i = 0;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	count = i;
	while (i > 0 && count != -1)
	{
		if (!ft_putchar(buffer[--i]))
			count = -1;
	}
	free(buffer);
	return (count);
}
