#include "miniRT.h"

static int	draw_sphere(t_tree *tree);

static int	draw_sphere(t_tree *tree)
{
	t_tuple		origin;
	t_fl		wall_z;
	t_fl		wall_size;
	t_fl		pixel_size;
	t_fl		half;
	
	point_new(origin, 0, 0, -5);
	wall_z = 10.0;
	wall_size = 7.0;
	pixel_size = wall_size / HEIGHT;
	half = wall_size / 2;

	t_sphere	sphere;
	t_tuple		pos;
	t_tuple		center;
	t_xs		xs[2];
	t_xs		*hit_ptr;
	t_fl		world_x;
	t_fl		world_y;
	int			x;
	int			y;
	t_ray		ray;
	t_tuple		direction;

	hit_ptr = NULL;
	point_new(center, 0, 0, 0); 
	sphere_new(&sphere, center);
	canvas_put(tree->image, (t_trio){0});

	y = 0;
	while (y < HEIGHT) {
		world_y = half - pixel_size * y;
		x = 0;
		while (x < WIDTH)
		{
			world_x = -half + pixel_size * x;
			point_new(pos, world_x, world_y, wall_z);
			tuple_minus_get(direction, pos, origin);
			normalize_apply(direction);
			ray_new(ray, origin, direction);
			if (intersect_get(xs, &sphere, ray))
			{
				xs[0].next = &xs[1];
				hit(&hit_ptr, xs);
				if (hit_ptr)
					pixel_put(tree->image, x, y, (t_trio){1, 0, 0});
				hit_ptr = NULL;
			}
			x++;
		}
		y++;
	}
	return 0;
}

void	test_draw_sphere(t_tree *tree)
{
	window_init(&tree->window, &tree->image);
	mlx_loop_hook(tree->window, commands, tree);
	draw_sphere(tree);
	mlx_loop(tree->window);
	window_destroy(tree->window, tree->image);
}