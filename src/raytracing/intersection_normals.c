/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_normals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:59:18 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/27 19:06:25 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the normal vector resulting from the intersection of a ray
 *	and a plane.
*/
static t_vector	get_plane_normal(t_plane *pl, t_ray ray)
{
	t_vector	normal;

	normal = pl->normal;
	if (vect_dot(ray.dir, normal) > 0)
		normal = substract_vect((t_vector){0, 0, 0}, normal);
	return (normal);
}

/*
 *	Returns the normal vector resulting from the intersection of a ray
 *	and a cylinder. If the intersection point is on a disk, it returns the
 *	normal of the disk. If the intersection point is on the cylinder's height,
 *	it returns the normal of the axis.
*/
static t_vector	get_cylinder_normal(t_cylinder *cy, t_vector point)
{
	t_vector	normal;
	t_vector	c1_to_point;
	t_vector	c2_to_point;
	double		s1;
	double		s2;

	c1_to_point = substract_vect(point, cy->pos);
	s1 = vect_dot(c1_to_point, cy->axis);
	if (fabs(s1) < PRECISION)
		return (substract_vect((t_vector){0, 0, 0}, cy->axis));
	c2_to_point = substract_vect(point, add_vect(cy->pos, \
		multiply_vect_scalar(cy->axis, cy->height)));
	s2 = vect_dot(c2_to_point, cy->axis);
	if (fabs(s2) < PRECISION)
		return (cy->axis);
	normal = normalize_vect(substract_vect(c1_to_point, \
			multiply_vect_scalar(cy->axis, s1)));
	return (normal);
}

/*
 *	Returns the normal vector resulting from the intersection of a ray
 *	and a cone.
*/
static t_vector	get_cone_normal(t_cone *co, t_vector point)
{
	t_vector	normal;
	t_vector	tip;
	t_vector	proj;
	double		tan2;
	double		d;

	tip = add_vect(co->pos, multiply_vect_scalar(co->axis, co->height));
	if (fabs(vect_dot(substract_vect(co->pos, point), co->axis)) < PRECISION)
		return (substract_vect((t_vector){0, 0, 0}, co->axis));
	tan2 = co->radius * co->radius / (co->height * co->height);
	d = vect_length(substract_vect(point, tip)) * sqrt(1 + tan2);
	proj = add_vect(tip, multiply_vect_scalar(\
		substract_vect((t_vector){0, 0, 0}, co->axis), d));
	normal = normalize_vect(substract_vect(point, proj));
	return (normal);
}

/*
 *	Returns the normal vector resulting from the intersection of a ray
 *	and an object, starting from the intersection point.
*/
t_vector	get_obj_normal(t_obj *obj, t_vector intersection, t_ray ray)
{
	t_vector	normal;

	normal = (t_vector){0, 0, 0};
	if (obj->pl)
		normal = get_plane_normal(obj->pl, ray);
	else if (obj->sp)
		normal = normalize_vect(substract_vect(intersection, obj->sp->pos));
	else if (obj->cy)
		normal = get_cylinder_normal(obj->cy, intersection);
	else if (obj->co)
		normal = get_cone_normal(obj->co, intersection);
	return (normal);
}
