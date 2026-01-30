/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:27:56 by thblack-          #+#    #+#             */
/*   Updated: 2025/04/26 18:26:58 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		return (ft_strlen(src) + size);
	while (i < size - dstlen - 1 && src[i] != '\0')
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	if (size > 0)
		dst[i + dstlen] = '\0';
	return (dstlen + ft_strlen(src));
}
