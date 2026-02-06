/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:55:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/05 09:13:25 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// static void    instruct(void);

int	main(int ac, char **av)
{
	t_tree	t;

	(void)av;
	(void)t;
	if (ac == 2)
	{
		test_rays();
		return (0);
		// parse();    //      -> check & fetch scene
		// initialise();   //  -> wrap up a handy struct(s)
		// trace();    //      -> the BIG LOOP(S) OF MATHS.
		// render();   //      -> MLX images
		// cleanup();  //      -> free allocations / mutexes
		// threads/ anything else..
	}
	else
	{
		transformation_test();
		// projectile_test(&t);
		// test_matrix();
		// vector_new(a, 1, 2, 3);
		// tuple_print(a);
		// vector_normalise(a, a);
		// tuple_print(a);
		// instruct();
	}
	return (0);
}

// static void    instruct(void)
// {
//     printf("\nUsage:\n\t./miniRT <scene description as a .rt <file>\n");
// }

// static void    trace(void)
// {
//     while (x < image_width)
//     {
//         while (y < image_height)
//         {
//             ray_generation();   //primary rays(intersects)
//             while (k < n_objects)
//             {
//                 intersections();
//                 shading(); //secondary rays(diffuse)
//             }
//         }
//     }
// }
