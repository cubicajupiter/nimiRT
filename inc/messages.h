/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:39:24 by thblack-          #+#    #+#             */
/*   Updated: 2026/02/13 14:13:50 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define MSG_MISSING_RT "\
miniRT expects an *.rt file defining the scene to be rendered\n\
Example usage: ./miniRT scene.rt\n"
# define MSG_INVALID_RT "\
miniRT expects an *.rt that adheres to a certain format\n\
RT file formatting rules:\n\
- Each type of element can be separated by one or more line breaks.\n\
- Each type of information from an element can be separated by one or more\n\
  spaces.\n\
- Each type of element can be set in any order in the file.\n\
- Elements defined by a capital letter can only be declared once in the\n\
  scene.\n\
- The first piece of information for each element is the type identifier\n\
  (composed of one or two characters), followed by all specific information\n\
  for each object in a strict order\n\
Examples of elements and the order of their data:\n\
- Ambient lighting: A 0.2 255,255,255\n\
  (ID, brightness [0.0-1.0], RGB color [0-255])\n\
- Camera: C -50.0,0,20 0,0,1 70\n\
  (ID, XYZ viewpoint [float], XYZ orientation [float], field-of-view [0-180])\n\
- Light: L -40.0,50.0,0.0 0.6\n\
  (ID, XYZ light position [float], brightness [0.0-1.0])\n\
- Sphere: sp 0.0,0.0,20.6 12.6 10,0,255\n\
  (ID, XYZ position [float], diameter [float], RGB color [0-255])\n\
- Plane: pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,255\n\
  (ID, XYZ point in plane [float], XYZ vector [float], RGB color [0-255])\n\
- Cylinder: cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255\n\
  (ID, XYZ position [float], XYZ axis vector [float], diameter [float]\n\
  height [float], RGB color [0-255])\n"

/*
// NOTE: Add for bonus
// - Light: L -40.0,50.0,0.0 0.6 10,0,255\n\
//   (ID, XYZ light position [float], brightness [0.0-1.0], RGB color [0-255])\n\
*/

#endif
