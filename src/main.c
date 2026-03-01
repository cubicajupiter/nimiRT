/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:55:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/03/01 10:23:07 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	t_tree		tree;
	t_run_mode	mode;
	int			flag;

	if (ac < 2 || !access_try(av[1], O_RDONLY))
		return (rt_missing(av[1]));
	mode = RELEASE;
	if (ac > 2)
	{
		flag = mode_parse(&mode, av[2]);
		if (flag != SUCCESS)
			return (error_exit(flag, &tree));
	}
	flag = init(&tree, av[1]);
	if (flag != SUCCESS)
		return (error_exit(flag, &tree));
	if (mode != RELEASE)
		debug(&tree, mode);
	if (ray_trace(&tree) != SUCCESS)
		return (error_exit(flag, &tree));
	mlx_loop(tree.window);
	if (errno)
		ft_perror();
	memory_free(&tree);
	return (EXIT_SUCCESS);
}

// OLD TESTS
	// if (ac == 2)
	// {
	// 	test_matrix();
	// 	test_rays(&tree);
	// 	parse();    //      -> check & fetch scene
	// 	initialise();   //  -> wrap up a handy struct(s)
	// 	trace();    //      -> the BIG LOOP(S) OF MATHS.
	// 	render();   //      -> MLX images
	// 	cleanup();  //      -> free allocations / mutexes
	// 	threads/ anything else..
	// }
	// else
	// {
	// 	transformation_test(&tree);
	// 	projectile_test(&t);
	// 	test_matrix();
	// 	vector_new(a, 1, 2, 3);
	// 	tuple_print(a);
	// 	vector_normalise(a, a);
	// 	tuple_print(a);
	// 	instruct();
	// }
