/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:53:04 by thblack-          #+#    #+#             */
/*   Updated: 2025/05/02 14:48:22 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	pre;
	size_t	post;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	pre = 0;
	post = s1_len;
	while (ft_strchr(set, s1[pre]))
		pre++;
	while (ft_strchr(set, s1[post - 1]))
		post--;
	if (pre >= s1_len || post <= 0)
		return (ft_strdup(""));
	return (ft_substr(s1, pre, post - pre));
}
