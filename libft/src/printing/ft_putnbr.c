/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:21:57 by thblack-          #+#    #+#             */
/*   Updated: 2025/07/22 11:23:17 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putnbr(int n)
{
	int	count;
	int	temp;

	if (n == -2147483648)
	{
		if (!ft_putstr("-2147483648"))
			return (-1);
		return (11);
	}
	count = 0;
	if (n < 0)
	{
		if (!ft_putchar('-'))
			return (-1);
		n = -n;
		count = 1;
	}
	temp = ft_putuint((unsigned int)n);
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}
