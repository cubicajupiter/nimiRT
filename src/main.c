/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:55:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/13 17:35:10 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "libft.h"
#include "messages.h"
#include "miniRT.h"
#include <stdlib.h>

static int	rt_missing(void);
static int	mode_prompt(void);
static int	mode_parse(t_run_mode *mode, char *flag);

int	main(int ac, char **av)
{
	t_tree		tree;
	t_run_mode	mode;
	int			flag;

	if (ac < 2)
		return (rt_missing());
	if (ac > 2)
	{
		flag = mode_parse(&mode, av[2]);
		if (flag != SUCCESS)
			return (error_exit(flag, &tree));
	}
	flag = init(&tree, av[1]);
	if (flag != SUCCESS)
			return (error_exit(flag, &tree));
	if (mode != NORMAL)
		debug(&tree, mode);
	if (ray_trace(&tree) != SUCCESS)
		return (error_exit(flag, &tree));
	if (errno)
		ft_perror();
	memory_free(&tree);
	return (EXIT_SUCCESS);
}

static int	rt_missing(void)
{
	ft_putendl_fd("Error\n", 2);
	ft_putendl_fd(MSG_MISSING_RT, 2);
	return (1);
}

static int	mode_prompt(void)
{
	ft_putendl_fd("Error\n", 2);
	ft_putendl_fd(MSG_MODE_PROMPT, 2);
	return (1);
}

static int	mode_parse(t_run_mode *mode, char *flag)
{
	if (!mode || !flag)
		return (ft_error(EINVAL, "mode_parse"));
	if (flag[0] != '-' || !flag[1])
		return (mode_prompt());
	if (flag[1] == 'i')
		*mode = INPUT_DEBUG;
	else if (flag[1] == 'f')
		*mode = FULL_DEBUG;
	else
		return (mode_prompt());
	return (SUCCESS);
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
