/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:20:52 by thblack-          #+#    #+#             */
/*   Updated: 2025/05/06 14:51:02 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static size_t	ft_wcount(char const *s, char c)
{
	size_t	wcount;

	wcount = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			wcount++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (wcount);
}

static void	ft_findword(int *word, char const *s, char c, size_t windex)
{
	size_t	wcount;
	size_t	i;

	wcount = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			word[0] = i;
			word[1] = 0;
			while (s[i] != c && s[i])
			{
				word[1]++;
				i++;
			}
			if (wcount++ == windex)
				return ;
		}
		else
			i++;
	}
}

static void	ft_freearray(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	wcount;
	int		word[2];
	size_t	i;

	if (!s)
		return (NULL);
	wcount = ft_wcount(s, c);
	array = malloc((wcount + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < wcount)
	{
		ft_findword(word, s, c, i);
		array[i] = malloc((word[1] + 1) * sizeof(char));
		if (!array[i])
			return (ft_freearray(array), NULL);
		ft_strlcpy(array[i], s + word[0], word[1] + 1);
		i++;
	}
	array[i] = NULL;
	return (array);
}
