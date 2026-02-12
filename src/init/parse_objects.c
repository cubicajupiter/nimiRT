/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:14:28 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/11 16:24:57 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// static int parse_sphere(t, line);
// static int parse_plane(t, line);
// static int parse_cylinder(t, line);

int	parse_objects(t_tree *t, char *line)
{
	(void)t;
	(void)line;
	// if (*line == 's')
	// 	return (parse_sphere(t, line));
	// else if (*line == 'p')
	// 	return (parse_plane(t, line));
	// else if (*line == 'c')
	// 	return (parse_cylinder(t, line));
	return (SUCCESS); // FIXME: Delete after other functions created
}

// static int parse_sphere(t, line)
// {
// }
//
// static int parse_plane(t, line)
// {
// }
//
// static int parse_cylinder(t, line)
// {
// }
