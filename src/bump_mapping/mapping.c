/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:43:28 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/26 17:53:03 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the corresponding color of a given texture for a point on a plane.
*/
t_color	plane_mapping(t_plane plane, t_map map, t_vector point, int ratio)
{
	t_vector	pl_to_p;
	int			x;
	int			y;

	pl_to_p = substract_vect(point, plane.pos);
	x = (int)(ratio * vect_dot(pl_to_p, plane.base[0]) + 2) % map.w;
	if (x < 0)
		x += map.w;
	y = (int)(ratio * vect_dot(pl_to_p, plane.base[1]) + 2) % map.h;
	if (y < 0)
		y += map.h;
	return (map.color[x][y]);
}

/*
 *	Returns the corresponding color of a given texture for a point on a sphere.
*/
t_color	sphere_mapping(t_sphere sphere, t_map map, t_vector normal)
{
	t_vector	n;
	int			x;
	int			y;

	n.x = vect_dot(normal, sphere.base[0]);
	n.y = vect_dot(normal, sphere.base[1]);
	n.z = vect_dot(normal, sphere.base[2]);
	x = (atan2(n.z, n.x) / (2 * M_PI) + 0.5) * (map.w - 1);
	y = (asin(-n.y) / M_PI + 0.5) * (map.h - 1);
	return (map.color[x][y]);
}

/*
 *	Returns the corresponding color of a given texture for a point on a
 *	cylinder.
*/
t_color	cylinder_mapping(t_cylinder cylinder, t_map map, \
		t_vector point, t_vector normal)
{
	t_vector	cy_to_p;
	t_plane		disk;
	t_vector	n;
	int			x;
	int			y;

	cy_to_p = substract_vect(point, cylinder.pos);
	disk.base[0] = cylinder.base[2];
	disk.base[1] = cylinder.base[0];
	disk.base[2] = cylinder.base[1];
	if (fabs(vect_dot(cy_to_p, cylinder.axis)) < PRECISION)
		return (disk.pos = cylinder.pos, plane_mapping(disk, map, point, \
			(int)cylinder.radius));
	else if (vect_dot(cy_to_p, cylinder.axis) > cylinder.height - PRECISION)
		return (disk.pos = add_vect(cylinder.pos, \
			multiply_vect_scalar(cylinder.axis, cylinder.height)), \
			plane_mapping(disk, map, point, (int)1 / cylinder.radius * 100));
	n.x = vect_dot(normal, cylinder.base[0]);
	n.y = vect_dot(cy_to_p, cylinder.base[1]);
	n.z = vect_dot(normal, cylinder.base[2]);
	x = (atan2(n.z, n.x) / (2 * M_PI) + 0.5) * (map.w - 1);
	y = n.y / cylinder.height * (map.h - 1);
	return (map.color[x][y]);
}

