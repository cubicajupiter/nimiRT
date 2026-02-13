/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:55:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/13 17:33:31 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "libft.h"
#include "messages.h"
#include "miniRT.h"

int	program_exit(t_tree *t)
{
	ft_arena_free(&t->a_sys);
	ft_arena_free(&t->a_buf);
	return (SUCCESS);
}

int	rt_missing(void)
{
	ft_putendl_fd("Error\n", 2);
	ft_putendl_fd(MSG_MISSING_RT, 2);
	return (1);
}

int	mode_prompt(void)
{
	ft_putendl_fd("Error\n", 2);
	ft_putendl_fd(MSG_MODE_PROMPT, 2);
	return (1);
}

int	mode_parse(t_run_mode *mode, char *flag)
{
	if (!mode || !flag)
		return (ft_error(EINVAL, "mode_parse"));
	if (flag[0] != '-' || !flag[1])
		return (FAIL);
	if (flag[1] == 'i')
		*mode = INPUT_DEBUG;
	else if (flag[1] == 'f')
		*mode = FULL_DEBUG;
	else
		return (FAIL);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_tree		tree;
	t_run_mode	mode;
	int			flag;

	(void)av;
	if (ac < 2)
		return (rt_missing());
	if (ac > 2)
		if (mode_parse(&mode, av[2]) != SUCCESS)
			return (mode_prompt());
	flag = init(&tree, av[1]);
	if (flag != SUCCESS)
	{
		if (errno)
			ft_perror();
		return (errno);
	}
	if (mode == INPUT_DEBUG)
		scene_data_print(&tree);
	if (ac == 2)
	{
		lighting_test(&tree);
		//test_matrix();
		//test_rays();
		//test_draw_sphere(&tree);
		//test_rays(&tree);
		// parse();    //      -> check & fetch scene
		// initialise();   //  -> wrap up a handy struct(s)
		// trace();    //      -> the BIG LOOP(S) OF MATHS.
		// render();   //      -> MLX images
		// cleanup();  //      -> free allocations / mutexes
		// threads/ anything else..
	}
	else
	{
		// transformation_test(&tree);
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
