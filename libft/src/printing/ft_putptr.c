/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:04:56 by thblack-          #+#    #+#             */
/*   Updated: 2025/07/22 11:27:53 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putptr(va_list args)
{
	int				count;
	int				temp;
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(args, void *);
	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	if (count < 0)
		return (-1);
	temp = ft_puthex(ptr, "0123456789abcdef");
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}
