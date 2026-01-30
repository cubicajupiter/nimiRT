/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:55:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 10:56:57 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"

void    instruct(void);

int main(int ac, char **av)
{
    if (ac == 2)
    {
        parse();    //      -> check & fetch scene
        initialise();   //  -> wrap up a handy struct(s)
        trace();    //      -> the BIG LOOP(S) OF MATHS.
        render();   //      -> MLX images
        cleanup();  //      -> free allocations / mutexes / threads/ anything else..
    }
    else
        instruct();
    return (0);
}

static void    instruct(void)
{
    printf("\nUsage:\n\t./miniRT <scene description as a .rt file>\n");
}

static void    trace(void)
{
    while (x < image_width)
    {
        while (y < image_height)
        {
            ray_generation();   //primary rays(intersects)
            while (k < n_objects)
            {
                intersections();     
                shading(); //secondary rays(diffuse)
            }
        }
    }
}