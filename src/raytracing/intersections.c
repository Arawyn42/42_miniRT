/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:02:56 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/02 15:08:33 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the distance from the ray's origin to the intersection point
 *	with a plane.
*/
double	pl_intersection(t_ray ray, t_plane *pl)
{
	double		scalar;
	t_point		ray_to_pl;

	scalar = vect_dot(ray.dir, *pl->normal);
	if (fabs(scalar) < PRECISION)
		return (INFINITY);
	ray_to_pl = substract_vect(*pl->pos, ray.origin);
	return (vect_dot(*pl->normal, ray_to_pl) / scalar);
}

/*
 *	Returns the distance from the ray's origin to the intersection point
 *	with a sphere.
*/
double	sp_intersection(t_ray ray, t_sphere *sp)
{
	t_point	ray_to_sp;
	double	a;
	double	b;
	double	c;

	ray_to_sp = substract_vect(ray.origin, *sp->pos);
	a = vect_dot(ray.dir, ray.dir);
	b = 2 * vect_dot(ray_to_sp, ray.dir);
	c = vect_dot(ray_to_sp, ray_to_sp) - sp->radius * sp->radius;
	return (quadratic_min(a, b, c, PRECISION));
}

/*
 *	Returns the distance from the ray's origin to the intersection point
 *	with an object.
*/
double	obj_intersection(t_ray ray, t_obj *obj)
{
	if (!obj)
		return (INFINITY);
	if (obj->pl)
		return (pl_intersection(ray, obj->pl));
	else if (obj->sp)
		return (sp_intersection(ray, obj->sp));
	// else if (obj->cy)
	// 	return (cy_intersection(ray, obj->cy));
	else
		return (INFINITY);
}

/*
 *	Returns the closest object from ray's origin and its distance from it.
*/
t_closest_obj	closest_intersection(t_ray ray, t_obj *objs)
{
	double			distance;
	double			closest_distance;
	t_obj			*obj;
	t_obj			*closest;
	t_closest_obj	res;

	closest = NULL;
	closest_distance = INFINITY;
	obj = objs;
	while (obj)
	{
		distance = obj_intersection(ray, obj);
		if (distance > PRECISION && distance < closest_distance)
		{
			closest_distance = distance;
			closest = obj;
		}
		obj = obj->next;
	}
	res.obj = closest;
	res.distance = closest_distance;
	return (res);
}

/*
 *	Returns the normal vector resulting from the intersection of a ray
 *	and an object, starting from the intersection point.
*/
t_point	get_obj_normal(t_obj *obj, t_point intersection, t_point dir)
{
	t_point	normal;

	if (obj->pl)
	{
		normal = normalize_vect(*obj->pl->normal);
		if (vect_dot(normal, dir) > 0)
		{
			normal = substract_vect((t_point){0, 0, 0}, normal);
			*obj->pl->normal = normal;
		}
	}
	if (obj->sp)
		normal = normalize_vect(substract_vect(intersection, *obj->sp->pos));
	// if (obj->cy)
		
	return (normal);
}
