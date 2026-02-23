/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:20:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/23 12:46:45 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * float_print() aligns numbers regardless of sign (minus or positive)
*/

int	float_print(const t_fl fl)
{
	if (is_float_equal(fl, 0.0f))
	{
		if (printf(" %f", 0.0f) < 0)
		{
			ft_error(EINHERIT, "printf");
			return (ft_error(EINHERIT, "float_print"));
		}
	}
	else if (fl < 0.0f)
	{
		if (printf("%f", fl) < 0)
		{
			ft_error(EINHERIT, "printf");
			return (ft_error(EINHERIT, "float_print"));
		}
	}
	else
	{
		if (printf(" %f", fl) < 0)
		{
			ft_error(EINHERIT, "printf");
			return (ft_error(EINHERIT, "float_print"));
		}
	}
	return (SUCCESS);
}

int	int_print(int nbr)
{
	if (nbr < 0.0f)
	{
		if (printf("%d", nbr) < 0)
		{
			ft_error(EINHERIT, "printf");
			return (ft_error(EINHERIT, "int_print"));
		}
	}
	else
	{
		if (printf(" %d", nbr) < 0)
		{
			ft_error(EINHERIT, "printf");
			return (ft_error(EINHERIT, "int_print"));
		}
	}
	return (SUCCESS);
}
