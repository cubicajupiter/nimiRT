/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error_messages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:03:47 by thblack-          #+#    #+#             */
/*   Updated: 2026/03/10 16:13:48 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "miniRT.h"
#include "messages.h"

/*
rt_missing()
Prints a custom error message letting the user know the *.rt file is missing
*/
int	rt_missing(char *path)
{
	ft_putendl_fd("Error\n", 2);
	if (path)
	{
		ft_putstr_fd("File at path ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(" not accessible or does not exit\n\n", 2);
	}
	ft_putendl_fd(MSG_MISSING_RT, 2);
	return (1);
}

/*
rt_invalid()
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
		ft_putstr_fd("'\n\n", 2);
	}
	ft_putendl_fd(MSG_INVALID_RT, 2);
	return (FAIL);
}

/*
rt_invlid()
Prints a custom error message letting the user know where an *.rt file might
contain a bad syntax.
*/
int	rt_zerovector(char *value)
{
	ft_putendl_fd("Error\n", 2);
	if (value)
	{
		ft_putstr_fd("Value of ", 2);
		ft_putstr_fd(value, 2);
		ft_putstr_fd(" vector has an illogical magnitude of zero\n\n", 2);
	}
	ft_putendl_fd(MSG_INVALID_RT, 2);
	return (FALSE);
}

/*
rt_invlid()
Prints a custom error message letting the user know where an *.rt file might
contain a bad syntax.
*/
int	rt_no_camera(void)
{
	ft_putstr_fd("Error\n\n", 2);
	ft_putstr_fd("File needs to define a camera in order to view the scene\n\n", 2);
	ft_putendl_fd(MSG_INVALID_RT, 2);
	return (FALSE);
}
