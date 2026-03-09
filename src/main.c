/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:55:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/03/09 18:50:20 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	input_handle_and_init(t_tree *tree, int ac, char **av);
static int	ray_multithread(t_tree *t);

int	main(int ac, char **av)
{
	t_tree		tree;
	int			flag;

	if (ac < 2 || !access_try(av[1], O_RDONLY))
		return (rt_missing(av[1]));
	flag = input_handle_and_init(&tree, ac, av);
	if (flag != SUCCESS)
		return (error_exit(flag, &tree));
	// microsecond precision tracking of the performance of ray_trace()
	#define _GNU_SOURCE
	#include <time.h>
	struct timespec	ts; 
	clock_gettime(CLOCK_MONOTONIC, &ts);
	long long start_time = ((long long) ts.tv_sec * 1000000000LL + ts.tv_nsec) / 1000;
	if (ray_multithread(&tree) != SUCCESS)
		return (error_exit(flag, &tree));
	clock_gettime(CLOCK_MONOTONIC, &ts);
	long long end_time = ((long long) ts.tv_sec * 1000000000LL + ts.tv_nsec) / 1000;
	printf("Elapsed time: %lld microseconds\n", end_time - start_time);
	mlx_loop(tree.window);
	if (errno && errno != EAGAIN)
		ft_perror();
	free_and_destroy(&tree);
	return (EXIT_SUCCESS);
}

static int	input_handle_and_init(t_tree *tree, int ac, char **av)
{
	t_run_mode	mode;
	int			flag;

	mode = RELEASE;
	flag = SUCCESS;
	if (ac > 2)
	{
		flag = mode_parse(&mode, av[2]);
		if (flag != SUCCESS)
			return (flag);
	}
	flag = init(tree, av[1]);
	if (flag != SUCCESS)
		return (flag);
	if (mode != RELEASE)
		debug(tree, mode);
	return (flag);
}

static int	ray_multithread(t_tree *t)
{
	camera_compute(&t->scene->camera);
	if (threads_run(t) != SUCCESS)
	{
		threads_join(t);
		return (ERROR);
	}
	return (threads_join(t));
}
