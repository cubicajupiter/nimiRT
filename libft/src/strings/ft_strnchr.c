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

char	*ft_strnchr(const char *s, int c, int len)
{
	char	*sc;
	char	cc;
	int		i;

	sc = (char *)s;
	cc = (char)c;
	i = 0;
	if (cc == '\0')
		return (sc + ft_strlen(sc));
	while (i < len)
	{
		if (sc[i] == cc)
			return (sc);
		i++;
	}
	return (NULL);
}
