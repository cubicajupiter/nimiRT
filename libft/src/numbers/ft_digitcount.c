/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:43:19 by thblack-          #+#    #+#             */
/*   Updated: 2025/07/22 11:27:50 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_digitcount(unsigned int n, unsigned int base)
{
	int	count;

	if (base == 0)
		return (-1);
	count = 0;
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}
