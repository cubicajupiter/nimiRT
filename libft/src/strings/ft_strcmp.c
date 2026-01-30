/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:08:47 by thblack-          #+#    #+#             */
/*   Updated: 2025/08/11 15:14:17 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1c;
	unsigned char	*s2c;
	size_t			i;

	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	i = 0;
	while (s1c[i] != '\0' || s2c[i] != '\0')
	{
		if (s1c[i] != s2c[i])
			return (s1c[i] - s2c[i]);
		i++;
	}
	if (s1c[i] || s2c[i])
		return (-1);
	return (0);
}
