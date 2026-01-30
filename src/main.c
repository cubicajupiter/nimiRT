/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:55:42 by jvalkama          #+#    #+#             */
/*   Updated: 2026/01/30 09:28:18 by jvalkama         ###   ########.fr       */
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

void    instruct(void)
{
    printf("\nUsage:\n\t./miniRT <scene description as a .rt file>\n");
}

void    trace(void)
{
    while (x)
    {
        while (y)
        {
            ray();
            intersection();
            shading();
        }
    }
}