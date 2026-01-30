/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:53:34 by thblack-          #+#    #+#             */
/*   Updated: 2025/09/18 14:13:22 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	ft_nbrcpy(char *num, int n, int sign, int nlen)
{
	if (sign == -1)
		num[0] = '-';
	nlen -= 1;
	if (n > 9)
		ft_nbrcpy(num, n / 10, 1, nlen);
	num[nlen] = (n % 10) + '0';
}

static int	ft_nbrsize(int n)
{
	int	power;
	int	nlen;

	power = 1;
	nlen = 1;
	while (n / power > 9)
	{
		power *= 10;
		nlen += 1;
	}
	return (nlen);
}

static int	ft_nbrsign(int *n)
{
	int	sign;

	if (*n < 0)
	{
		sign = -1;
		*n = -*n;
	}
	else
		sign = 1;
	return (sign);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		nlen;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = ft_nbrsign(&n);
	nlen = ft_nbrsize(n);
	if (sign == -1)
		nlen += 1;
	num = malloc((nlen + 1) * sizeof(char));
	if (!num)
		return (NULL);
	ft_nbrcpy(num, n, sign, nlen);
	num[nlen] = '\0';
	return (num);
}
