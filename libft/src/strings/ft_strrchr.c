/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:59:16 by thblack-          #+#    #+#             */
/*   Updated: 2025/04/26 19:00:26 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sc;
	char	cc;

	sc = (char *)s + ft_strlen(s);
	cc = (char)c;
	if (c == '\0')
		return (sc);
	while (sc >= s)
	{
		if (*sc == cc)
			return (sc);
		sc--;
	}
	return (NULL);
}
