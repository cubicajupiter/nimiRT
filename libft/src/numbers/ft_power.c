/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:42:35 by thblack-          #+#    #+#             */
/*   Updated: 2025/10/01 16:42:57 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int base, int exponent)
{
	int	res;

	res = 1;
	if (exponent == 0)
		return (1);
	while (exponent-- > 0)
		res *= base;
	return (res);
}
