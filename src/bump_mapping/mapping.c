/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:43:28 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/25 23:54:25 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	plane_mapping(t_plane plane, t_map map, t_vector point)
{
	t_vector	pl_to_p;
	int			x;
	int			y;

	pl_to_p = substract_vect(point, plane.pos);
	x = (int)(30 * vect_dot(pl_to_p, plane.base[0]) + 2) % map.w;
	if (x < 0)
		x += map.w;
	y = (int)(30 * vect_dot(pl_to_p, plane.base[1]) + 2) % map.h;
	if (y < 0)
		y += map.h;
	return (map.color[x][y]);
}

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
