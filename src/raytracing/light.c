/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:25:40 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/02 00:02:21 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Returns the base color of an object.
*/
t_color	get_obj_color(t_obj *obj)
{
	if (obj->pl)
		return (int_to_rgb(obj->pl->color));
	else if (obj->sp)
		return (int_to_rgb(obj->sp->color));
	else if (obj->cy)
		return (int_to_rgb(obj->cy->color));
	else
		return ((t_color){0, 0, 0, 0});
}

/*
*	Returns the light intensity.
*/
t_point	light_intensity(t_data *data)
{
	t_point	res;
	t_color	light;

	light = int_to_rgb(data->light->color);
	res.x = data->light->ratio * light.r / light.sum;
	res.y = data->light->ratio * light.g / light.sum;
	res.z = data->light->ratio * light.b / light.sum;
	return (res);
}

double	diffuse_intensity(t_point normal, t_point distance)
{
	double	scalar;

	scalar = vector_scalar_product(distance, normal);
	if (scalar < PRECISION)
		return (0);
	return (scalar / get_vect_norm(distance));
}

float	specular_intensity(t_point distance, t_point normal, \
	t_point dir, double ratio)
{
	t_point		reflect;
	float		scalar;

	if (ratio < PRECISION)
		return (0);
	reflect = reflection_dir(normal, distance);
	scalar = vector_scalar_product(reflect, dir);
	if (scalar > 0)
		return (pow(scalar / (get_vect_norm(reflect) \
			* get_vect_norm(dir)), ratio));
	return (0);
}

t_point	point_intensity(t_light light, t_point normal, \
	t_point distance, t_point dir)
{
	t_point	intensity;
	t_color	light_color;
	double	ratio;

	light_color = int_to_rgb(light.color);
	ratio = light.ratio * (diffuse_intensity(normal, distance) \
		+ specular_intensity(distance, normal, dir, 2));
	intensity.x = ratio * light_color.r / light_color.sum;
	intensity.y = ratio * light_color.g / light_color.sum;
	intensity.z = ratio * light_color.b / light_color.sum;
	return (intensity);
}

/*
*	Returns the light intensity.
*/
static t_point	light_effects_intensity(t_data *data, \
	t_point normal, t_point inter, t_point dir)
{
	t_point			a_light;
	t_point			light;
	t_point			distance;
	t_closest_obj	closest;
	t_obj			*objs;

	a_light = ambient_lightning_intensity(data);
	light = ambient_lightning_intensity(data);
	objs = data->objs;
	while (objs)
	{
		if (objs->light)
		{
			distance = normalize_vect(substract_vect(*objs->light->pos, inter));
			closest = closest_intersection((t_ray){inter, distance}, objs);
			if (!closest.obj || closest.distance > get_vect_norm(distance))
				a_light = add_vect(a_light, point_intensity(*objs->light, \
					normal, distance, dir));
			light = add_vect(light, light_intensity(data));
		}
		objs = objs->next;
	}
	return ((t_point){a_light.x / light.x, \
		a_light.y / light.y, a_light.z / light.z});
}

/*
*	Returns the color resulting from a colored light applied
*	on a colored pixel.
*/
t_color	apply_light(t_data *data, t_point normal, t_closest_obj closest, t_ray ray)
{
	t_color	obj_color;
	t_color	color;
	t_point	intensity;
	t_point	inter;

	inter = intersection_point(ray, closest.distance);
	obj_color = get_obj_color(closest.obj);
	intensity = light_effects_intensity(data, normal, inter, \
		substract_vect((t_point){0, 0, 0}, ray.dir));
	color.r = obj_color.r * intensity.x;
	color.g = obj_color.g * intensity.y;
	color.b = obj_color.b * intensity.z;
	color.sum = color.r + color.g + color.b;
	protect_colors(&color);
	return (color);
}
