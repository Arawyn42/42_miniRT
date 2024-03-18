/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_normals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:59:18 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/18 16:27:30 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the normal vector resulting from the intersection of a ray
 *	and a cylinder. If the intersection point is on a disk, it returns the
 *	normal of the disk. If the intersection point is on the cylinder's height,
 *	it returns the normal of the axis.
*/
static t_vector	get_cylinder_normal(t_cylinder *cy, t_vector intersection)
{
	t_vector	normal;
	double		d;
	t_vector	center_to_point;

	center_to_point = substract_vect(intersection, cy->pos);
	d = vect_dot(center_to_point, cy->axis);
	if (fabs(fabs(d) - cy->height / 2) < PRECISION)
	{
		if (vect_dot(center_to_point, cy->axis) >= 0)
			normal = cy->axis;
		else
			normal = substract_vect((t_vector){0, 0, 0}, cy->axis);
	}
	else
		normal = substract_vect(center_to_point, \
			multiply_vect_scalar(cy->axis, d));
	normal = normalize_vect(normal);
	return (normal);
}

static t_vector	get_cone_normal(t_cone *co, t_vector p)
{
	t_vector	normal;
	t_vector	c;
	t_vector	proj;
	double		tan2;
	double		d;

	c = add_vect(co->pos, multiply_vect_scalar(co->axis, co->height));
	if (fabs(vect_dot(substract_vect(c, p), co->axis)) < PRECISION)
		return (co->axis);
	tan2 = co->radius * co->radius / (co->height * co->height);
	d = vect_length(substract_vect(p, co->pos)) * sqrt(1 + tan2);
	proj = add_vect(co->pos, multiply_vect_scalar(co->axis, d));
	normal = normalize_vect(substract_vect(p, proj));
	// printf("P = %f %f %f, proj = %f %f %f, Normal = %f %f %f\n", p.x, p.y, p.z, proj.x, proj.y, proj.z, normal.x, normal.y, normal.z);
	return (normal);
}

/*
 *	Returns the normal vector resulting from the intersection of a ray
 *	and an object, starting from the intersection point.
*/
t_vector	get_obj_normal(t_obj *obj, t_vector intersection)
{
	t_vector	normal;

	normal = (t_vector){0, 0, 0};
	if (obj->pl)
		normal = obj->pl->normal;
	else if (obj->sp)
		normal = normalize_vect(substract_vect(intersection, obj->sp->pos));
	else if (obj->cy)
		normal = get_cylinder_normal(obj->cy, intersection);
	else if (obj->co)
		normal = get_cone_normal(obj->co, intersection);
	return (normal);
}
