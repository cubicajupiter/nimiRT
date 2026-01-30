/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:54:15 by thblack-          #+#    #+#             */
/*   Updated: 2025/04/29 16:54:19 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*sc;

	len = ft_strlen(s);
	sc = malloc((len + 1) * sizeof(char));
	if (!sc)
		return (NULL);
	ft_strlcpy(sc, s, len + 1);
	return (sc);
}
