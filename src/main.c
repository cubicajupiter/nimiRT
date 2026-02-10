/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:55:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/10 18:00:31 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"

// static void    instruct(void);

int	program_init(t_tree *t)
{
	t->a_sys = NULL;
	t->a_buf = NULL;
	if (ft_arena_init(&t->a_sys, BUF_SIZE) != SUCCESS
		|| ft_arena_init(&t->a_buf, BUF_SIZE) != SUCCESS)
		return (ft_error(EINHERIT, "program_init"));
	return (SUCCESS);
}

int	program_exit(t_tree *t)
{
	ft_arena_free(&t->a_sys);
	ft_arena_free(&t->a_buf);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_tree	tree;

	(void)av;
	program_init(&tree);
	if (ac == 2)
	{
		//test_matrix();
		test_rays(&tree);
		// parse();    //      -> check & fetch scene
		// initialise();   //  -> wrap up a handy struct(s)
		// trace();    //      -> the BIG LOOP(S) OF MATHS.
		// render();   //      -> MLX images
		// cleanup();  //      -> free allocations / mutexes
		// threads/ anything else..
	}
	else
	{
		transformation_test(&tree);
		// projectile_test(&t);
		// test_matrix();
		// vector_new(a, 1, 2, 3);
		// tuple_print(a);
		// vector_normalise(a, a);
		// tuple_print(a);
		// instruct();
	}
	if (errno)
		ft_perror();
	program_exit(&tree);
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
