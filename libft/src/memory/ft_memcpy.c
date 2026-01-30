/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:13:42 by thblack-          #+#    #+#             */
/*   Updated: 2025/07/21 19:03:53 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destc;
	unsigned char	*srcc;

	i = 0;
	destc = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	while (i < n)
	{
		destc[i] = srcc[i];
		i++;
	}
	return (dest);
}
