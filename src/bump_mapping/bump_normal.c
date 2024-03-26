/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:13:19 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/26 16:47:54 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	plane_bump(t_plane plane, t_vector point)
{
	t_color		color;
	t_vector	m[3];
	t_vector	v;

	if (!plane.normal_map.color)
		return ((t_vector){0, 0, 0});
	color = plane_mapping(plane, plane.normal_map, point, 30);
	v = substract_vect(multiply_vect_scalar((t_vector) {color.r, color.g, \
		color.b}, 3.0 / 255), (t_vector){1.0, 1.0, 1.0});
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	m[0] = plane.base[0];
	m[1] = plane.base[1];
	m[2] = plane.base[2];
	transpose_matrix(m);
	inverse_matrix(m);
	return (normalize_vect(multiply_vect_matrix(v, m)));
}

static t_vector	sphere_bump(t_sphere sphere, t_vector normal)
{
	t_color		color;
	t_vector	m[3];
	t_vector	v;
	t_vector	n;

	if (!sphere.normal_map.color)
		return ((t_vector){0, 0, 0});
	color = sphere_mapping(sphere, sphere.normal_map, normal);
	v = substract_vect(multiply_vect_scalar((t_vector) {color.r, color.g, \
		color.b}, 3.0 / 255), (t_vector){1.0, 1.0, 1.0});
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	n.x = vect_dot(normal, sphere.base[0]);
	n.y = vect_dot(normal, sphere.base[1]);
	n.z = vect_dot(normal, sphere.base[2]);
	n = normalize_vect(n);
	m[0] = sphere_tangent(sphere.radius, atan2(n.z, 
	n.x), asin(-n.y) + M_PI / 2);
	m[1] = normalize_vect(vect_cross_product(m[0], n));
	m[2] = n;
	transpose_matrix(m);
	inverse_matrix(m);
	return (normalize_vect(multiply_vect_matrix(v, m)));
}

static t_vector	cylinder_bump(t_cylinder cylinder, \
		t_vector point, t_vector normal)
{
	t_color		color;
	t_vector	m[3];
	t_vector	v;
	t_vector	n;

	if (!cylinder.normal_map.color)
		return ((t_vector){0, 0, 0});
	color = cylinder_mapping(cylinder, cylinder.normal_map, point, normal);
	v = substract_vect(multiply_vect_scalar((t_vector) {color.r, color.g,
		color.b}, 3.0 / 255), (t_vector){1.0, 1.0, 1.0});
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	n.x = vect_dot(normal, cylinder.base[0]);
	n.y = vect_dot(normal, cylinder.base[1]);
	n.z = vect_dot(normal, cylinder.base[2]);
	n = normalize_vect(n);
	m[0] = cylinder_tangent(cylinder, 
	substract_vect(point, cylinder.pos), atan2(n.z, n.x));
	m[2] = normalize_vect(n);
	m[1] = normalize_vect(vect_cross_product(m[0], m[2]));
	inverse_matrix(m);
	transpose_matrix(m);
	return (normalize_vect(multiply_vect_matrix(v, m)));
}

t_vector	bump_normal(t_obj *obj, t_vector point, t_vector normal)
{
	(void) normal;
	if (obj->pl)
		return (plane_bump(*obj->pl, point));
	else if (obj->sp)
		return (sphere_bump(*obj->sp, normal));
	else if (obj->cy)
		return (cylinder_bump(*obj->cy, point, normal));
	return ((t_vector){0, 0, 0});
}
