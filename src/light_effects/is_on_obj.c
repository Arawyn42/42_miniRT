/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_on_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:16:26 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/21 14:25:47 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns 1 if the point is on the surface of the plane, 0 if not.
*/
static int	is_on_plane(t_plane plane, t_vector point)
{
	t_vector	normal;
	t_vector	point_to_pl;

	normal = plane.normal;
	point_to_pl = normalize_vect(substract_vect(plane.pos, point));
	if (fabs(vect_dot(point_to_pl, normal)) <= PRECISION)
		return (1);
	return (0);
}

/*
 *	Returns 1 if the point is on the surface of the sphere, 0 if not.
*/
static int	is_on_sphere(t_sphere sphere, t_vector point)
{
	t_vector	point_to_sp;
	double		radius;
	double		distance;

	point_to_sp = substract_vect(sphere.pos, point);
	radius = sphere.radius;
	distance = fabs(vect_length(point_to_sp));
	if (distance <= radius + PRECISION && distance >= radius - PRECISION)
		return (1);
	return (0);
}

/*
 *	Returns 1 if the point is on the surface of the cylinder, 0 if not.
*/
static int	is_on_cylinder(t_cylinder cylinder, t_vector point)
{
	t_vector	center;
	t_vector	axis;
	double		param;
	t_vector	proj;

	center = cylinder.pos;
	axis = cylinder.axis;
	param = (axis.x * (point.x - center.x) + axis.y * (point.y - center.y) \
		+ axis.z * (point.z - center.z)) \
		/ (axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
	proj = add_vect(center, multiply_vect_scalar(axis, param));
	if (vect_length(substract_vect(proj, point)) <= cylinder.radius + PRECISION
		&& vect_length(substract_vect(proj, center)) \
		<= cylinder.height + PRECISION)
		return (1);
	return (0);
}

/*
 *	Returns 1 if the point is on the surface of the cone, 0 if not.
*/
static int	is_on_cone(t_cone co, t_vector p)
{
	t_vector	c;
	double		dist;
	double		disk_dist;

	c = add_vect(co.pos, multiply_vect_scalar(co.axis, co.height));
	if (fabs(vect_dot(substract_vect(c, p), co.axis)) < PRECISION \
		&& vect_length(substract_vect(c, p)) <= co.radius)
		return (1);
	dist = vect_dot(substract_vect(p, co.pos), co.axis);
	if (dist <= 0 || dist > co.height)
		return (0);
	disk_dist = vect_length(substract_vect(substract_vect(p, co.pos), \
		multiply_vect_scalar(co.axis, dist)));
	if (disk_dist <= dist * co.radius / co.height + PRECISION)
		return (1);
	return (0);
}

/*
 *	Returns 1 if the point if on the surface of the closest object, 0 if not.
*/
int	is_on_obj(t_obj obj, t_vector point)
{
	if (obj.pl && is_on_plane(*obj.pl, point))
		return (1);
	else if (obj.sp && is_on_sphere(*obj.sp, point))
		return (1);
	else if (obj.cy && is_on_cylinder(*obj.cy, point))
		return (1);
	else if (obj.co && is_on_cone(*obj.co, point))
		return (1);
	else if (obj.light)
		return (1);
	return (0);
}
