/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:23:37 by thblack-          #+#    #+#             */
/*   Updated: 2025/04/26 17:58:09 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*destc;
	unsigned char	*srcc;

	i = 0;
	destc = (unsigned char *)dest;
	srcc = (unsigned char *)src;
	if (srcc < destc)
	{
		while (len > 0)
		{
			len--;
			*(destc + len) = *(srcc + len);
		}
	}
	else
	{
		while (i < len)
		{
			*(destc + i) = *(srcc + i);
			i++;
		}
	}
	return (dest);
}
