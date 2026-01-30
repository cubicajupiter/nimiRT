/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:17:47 by thblack-          #+#    #+#             */
/*   Updated: 2025/07/22 11:23:01 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putarg(char c, va_list args)
{
	int	count;

	if (c == 'c')
		count = ft_putchar((char)va_arg(args, int));
	if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	if (c == 'p')
		count = ft_putptr(args);
	if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(args, int));
	if (c == 'u')
		count = ft_putuint(va_arg(args, unsigned int));
	if (c == 'x')
		count = ft_puthex(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		count = ft_puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (count);
}

int	ft_checkspec(char c, va_list args)
{
	if (c == '%')
		return (ft_putchar(c));
	else if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X')
		return (ft_putarg(c, args));
	else
	{
		if (!ft_putchar('%'))
			return (-1);
		if (!ft_putchar(c))
			return (-1);
		return (2);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		temp;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (*++format == '\0')
				temp = -1;
			else
				temp = ft_checkspec(*format++, args);
		}
		else
			temp = ft_putchar(*format++);
		if (temp < 0)
			break ;
		count += temp;
	}
	if (temp < 0)
		count = -1;
	va_end(args);
	return (count);
}
