/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:00:20 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/18 02:32:02 by drenassi         ###   ########.fr       */
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

/*
 *	Returns 1 if the point is in the shadow of an object, 0 if not.
*/
int	is_in_shadow(t_data *data, t_vector point, t_light light)
{
	t_ray			p_to_l;
	double			l_distance;
	t_closest_obj	closest;

	if (!data->light)
		return (0);
	p_to_l.origin = point;
	p_to_l.dir = normalize_vect(substract_vect(light.pos, point));
	l_distance = vect_length(substract_vect(light.pos, point));
	closest = closest_intersection(data, p_to_l);
	if (!closest.obj || closest.obj->pl || closest.obj->light)
		return (0);
	if (closest.distance >= l_distance || is_on_obj(*closest.obj, point))
		return (0);
	return (1);
}
