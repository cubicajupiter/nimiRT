/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:05:46 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/02 10:23:58 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int ft_error(int code, char *message)
{
    if (code)
        errno = code;
    if (message && *message)
        printf("%s() fail\n", message);
    return (ERROR);
}
