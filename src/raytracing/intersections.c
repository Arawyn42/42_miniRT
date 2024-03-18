/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:02:56 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/18 00:46:43 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the distance from the ray's origin to the intersection point
 *	with a plane.
*/
static double	pl_intersection(t_ray ray, t_plane *pl)
{
	double		scalar;
	t_vector	ray_to_pl;

	scalar = vect_dot(ray.dir, pl->normal);
	if (fabs(scalar) < PRECISION)
		return (INFINITY);
	ray_to_pl = substract_vect(pl->pos, ray.origin);
	return (vect_dot(pl->normal, ray_to_pl) / scalar);
}

/*
 *	Returns the distance from the ray's origin to the intersection point
 *	with a sphere.
*/
static double	sp_intersection(t_ray ray, t_sphere *sp)
{
	t_vector	ray_to_sp;
	double		a;
	double		b;
	double		c;

	ray_to_sp = substract_vect(ray.origin, sp->pos);
	a = vect_dot(ray.dir, ray.dir);
	b = 2 * vect_dot(ray_to_sp, ray.dir);
	c = vect_dot(ray_to_sp, ray_to_sp) - sp->radius * sp->radius;
	return (quadratic(a, b, c, 0));
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
	else if (obj->cy)
		return (cy_intersection(ray, obj->cy));
	else if (obj->co)
		return (cone_intersection(ray, obj->co));
	return (INFINITY);
}

/*
 *	Returns the closest object from ray's origin and its distance from it.
*/
t_closest_obj	closest_intersection(t_data *data, t_ray ray)
{
	double			distance;
	t_obj			*obj;
	t_closest_obj	res;

	res.obj = NULL;
	res.distance = INFINITY;
	res.reflect = DEFAULT_REFLECT_RATIO;
	obj = data->objs;
	while (obj)
	{
		distance = obj_intersection(ray, obj);
		if (distance > PRECISION && distance < res.distance)
		{
			res.obj = obj;
			res.distance = distance;
			res.reflect = get_obj_reflect_ratio(obj);
		}
		obj = obj->next;
	}
	return (res);
}
