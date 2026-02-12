/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:56:38 by jvalkama          #+#    #+#             */
/*   Updated: 2026/02/12 14:00:52 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

# define EYE 0
# define NORMAL 1

void		reflecton_ambient(t_material *mat, t_light *light);
void		reflection_diffuse(t_material *m, t_fl light_dot);
void		reflection_specular(t_material *m, t_light *l, t_fl eye_dot);
int			reflection(t_tuple dst, t_tuple in, t_tuple normal);

#endif