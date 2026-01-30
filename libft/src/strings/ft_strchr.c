/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 22:38:24 by thblack-          #+#    #+#             */
/*   Updated: 2025/04/25 18:19:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*sc;
	char	cc;

	sc = (char *)s;
	cc = (char)c;
	if (cc == '\0')
		return (sc + ft_strlen(sc));
	while (*sc != '\0')
	{
		if (*sc == cc)
			return (sc);
		sc++;
	}
	return (NULL);
}
