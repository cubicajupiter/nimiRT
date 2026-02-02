/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:55:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/31 17:12:18 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// static void    instruct(void);

void    commands(void *data)
{
    t_tree  *t;

    t = (t_tree *)data;
	if (mlx_is_key_down(t->window, MLX_KEY_ESCAPE))
		mlx_close_window(t->window);
}

int main(int ac, char **av)
{
    t_tree  t;

    (void)av;
    if (ac == 2)
    {
        return (0);
        // parse();    //      -> check & fetch scene
        // initialise();   //  -> wrap up a handy struct(s)
        // trace();    //      -> the BIG LOOP(S) OF MATHS.
        // render();   //      -> MLX images
        // cleanup();  //      -> free allocations / mutexes / threads/ anything else..
    }
    else
    {
        window_init(&t.window, &t.image);
        mlx_loop_hook(t.window, commands, &t);
        throw();
        mlx_loop(t.window);
        window_destroy(t.window);
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
