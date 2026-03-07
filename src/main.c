/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:55:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/03/06 17:49:14 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	input_handle(t_tree *tree, int ac, char **av);
static void	ray_trace(t_tree *t);

int	main(int ac, char **av)
{
	t_tree		tree;
	int			flag;

	if (ac < 2 || !access_try(av[1], O_RDONLY))
		return (rt_missing(av[1]));
	flag = input_handle(&tree, ac, av);
	if (flag != SUCCESS)
		return (error_exit(flag, &tree));
	
	//microsecond precision tracking of the performance of ray_trace()
	#define _GNU_SOURCE
	#include <time.h>
	struct timespec ts; 
	clock_gettime(CLOCK_MONOTONIC, &ts);
	long long start_time = ((long long) ts.tv_sec * 1000000000LL + ts.tv_nsec) / 1000;

	ray_trace(&tree);

	clock_gettime(CLOCK_MONOTONIC, &ts);
	long long end_time = ((long long) ts.tv_sec * 1000000000LL + ts.tv_nsec) / 1000;
	printf("Elapsed time: %lld microseconds\n", end_time - start_time);

	mlx_loop(tree.window);
	if (errno)
		ft_perror();
	memory_free(&tree);
	return (EXIT_SUCCESS);
}

static int	input_handle(t_tree *tree, int ac, char **av)
{
	t_run_mode	mode;
	int			flag;

	mode = RELEASE;
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

static void	ray_trace(t_tree *t)
{
	t_xs	hit;
	t_ray	ray;
	size_t	x;
	size_t	y;

	camera_compute(&t->scene->camera);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_ray_get(ray, &t->scene->camera, x, y);
			if (ray_to_scene_hit_get(&hit, ray, t->scene))
			{
				hit_shade(&hit, ray, t->scene);
				pixel_put(t->image, x, y, hit.object->material.shader.combined);
			}
			++x;
		}
		++y;
	}
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
