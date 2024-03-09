/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_normals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:59:18 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/09 15:09:15 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the normal vector resulting from the intersection of a ray
 *	and a cylinder. If the intersection point is on a disk, it returns the
 *	normal of the disk. If the intersection point is on the cylinder's height,
 *	it returns the normal of the axis.
*/
static t_point	get_cylinder_normal(t_cylinder *cy, t_point intersection)
{
	t_point	normal;
	double	d;
	t_point	center_to_point;

	center_to_point = substract_vect(intersection, cy->pos);
	d = vect_dot(center_to_point, cy->axis);
	if (fabs(fabs(d) - cy->height / 2) < PRECISION)
	{
		if (vect_dot(center_to_point, cy->axis) >= 0)
			normal = cy->axis;
		else
			normal = substract_vect((t_point){0, 0, 0}, cy->axis);
	}
	else
		normal = substract_vect(center_to_point, multiply_vect(cy->axis, d));
	normal = multiply_vect(normal, 1 / vect_length(normal));
	return (normal);
}

/*
 *	Returns the normal vector resulting from the intersection of a ray
 *	and an object, starting from the intersection point.
*/
t_point	get_obj_normal(t_obj *obj, t_point intersection)
{
	t_point	normal;

	normal = (t_point){0, 0, 0};
	if (obj->pl)
		normal = obj->pl->normal;
	else if (obj->sp)
		normal = normalize_vect(substract_vect(intersection, obj->sp->pos));
	else if (obj->cy)
		normal = get_cylinder_normal(obj->cy, intersection);
	return (normal);
}
