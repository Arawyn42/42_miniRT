/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:21:40 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/09 19:28:00 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Initialize the primary ray, starting from camera's position in camera's
 *	direction.
*/
void	init_ray(t_data *data, t_ray *ray)
{
	ray->origin = data->camera->pos;
	ray->dir = data->camera->direction;
}

/*
 *	Returns the ray intersection point coordinates from the ray's origin.
*/
t_vector	intersection_point(t_ray ray, double distance)
{
	t_vector	intersection;

	intersection = add_vect(ray.origin, multiply_vect(ray.dir, distance));
	return (intersection);
}

/*
 *	Returns the ray's direction and lenght.
*/
t_vector	set_ray(t_vector base[3], double x, double y, double z)
{
	t_vector	new;

	new.x = base[0].x * x + base[1].x * y + base[2].x * z;
	new.y = base[0].y * x + base[1].y * y + base[2].y * z;
	new.z = base[0].z * x + base[1].z * y + base[2].z * z;
	return (new);
}

/*
 *	Traces the primary ray. It will stop at the first intersection with
 *	an object, change the color of the intersection point, then reflect
 *	back in a recursive way.
*/
t_color	ray_trace(t_data *data, t_ray ray, int depth)
{
	t_closest_obj	closest;
	t_vector		closest_normal;
	t_color			color;
	t_color			reflect_color;

	closest = closest_intersection(ray, data->objs);
	if (!closest.obj)
		return ((t_color){0, 0, 0, 0});
	closest_normal = get_obj_normal(closest.obj, \
	intersection_point(ray, closest.distance));
	color = light_effects(data, closest_normal, closest, ray);
	if (depth <= 0 || closest.reflect <= 0)
		return (color);
	ray.origin = intersection_point(ray, closest.distance);
	ray.dir = reflection_dir(closest_normal, \
		substract_vect((t_vector){0, 0, 0}, ray.dir));
	reflect_color = ray_trace(data, ray, depth - 1);
	return (reflection_color(color, reflect_color, closest.reflect));
}
