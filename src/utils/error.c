/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:05:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/17 13:56:55 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "messages.h"

int	ft_error(int code, const char *message)
{
	if (code)
		errno = code;
	if (message && *message)
		printf("Error: %s() fail\n", message);
	return (ERROR);
}

/*
rt_invlid()
Prints a custom error message letting the user know where an *.rt file might
contain a bad syntax.
*/
int	rt_invalid(char c)
{
	ft_putendl_fd("Error\n", 2);
	if (c)
	{
		ft_putstr_fd("Syntax error near '", 2);
		ft_putchar_fd(c, 2);
		ft_putendl_fd("'\n", 2);
	}
	ft_putendl_fd(MSG_INVALID_RT, 2);
	return (FAIL);
}

/*
rt_out_of_limits()
Prints a custom error message letting the user know where an *.rt file might
contain a value that falls outside set limits.
*/
bool	rt_out_of_limits(char *value)
{
	ft_putendl_fd("Error\n", 2);
	if (value)
	{
		ft_putstr_fd("Value of ", 2);
		ft_putstr_fd(value, 2);
		ft_putendl_fd(" outside of limits", 2);
	}
	ft_putendl_fd(MSG_INVALID_RT, 2);
	return (false);
}
