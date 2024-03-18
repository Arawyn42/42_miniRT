/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_effects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:20:04 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/17 20:03:11 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the diffuse intensity, which is the scalar product between
 *	the vector from light position to the intersection point and
 *	the normal vector at the intersection point.
*/
static double	diffuse_intensity(t_vector normal, t_vector p_to_l)
{
	double	ratio;

	ratio = vect_dot(p_to_l, normal);
	if (ratio < PRECISION)
		return (0);
	return (ratio);
}

/*
 *	Returns the specular intensity, which is the scalar product between
 *	the reflection vector and the vector from light position to the
 *	intersection point.
*/
static double	specular_intensity(t_vector p_to_l, t_vector normal, \
	t_vector dir, t_closest_obj closest)
{
	t_vector	reflect;
	double		scalar;
	double		intensity;

	if (closest.obj->pl || closest.reflect > 0)
		return (0);
	reflect = reflection_dir(normal, p_to_l);
	scalar = vect_dot(reflect, dir);
	intensity = fabs(pow(scalar, 30) * 0.002);
	if (scalar > PRECISION && intensity > PRECISION)
		return (intensity);
	return (0);
}

/*
 *	Applies diffuse intensity and specular intensity on light ratio
 *	and returns the resulting light intensity as a vector.
*/
static t_vector	point_intensity(t_light light, t_vector normal_dir[2], \
	t_vector p_to_l, t_closest_obj closest)
{
	t_vector	intensity;
	t_color		light_color;
	double		ratio;

	light_color = int_to_rgb(light.color);
	ratio = light.ratio * (diffuse_intensity(normal_dir[0], p_to_l) \
		+ specular_intensity(p_to_l, normal_dir[0], normal_dir[1], closest));
	intensity.x = ratio * light_color.r / light_color.sum;
	intensity.y = ratio * light_color.g / light_color.sum;
	intensity.z = ratio * light_color.b / light_color.sum;
	return (intensity);
}

/*
*	Returns the light intensity vector after applying the ambient
*	lightning ratio on the diffuse intensity and on the specular
*	intensity.
*/
static t_vector	light_effects_intensity(t_data *data, \
	t_vector normal_dir[2], t_vector inter, t_closest_obj closest)
{
	t_vector	p_intensity;
	t_vector	l_intensity;
	t_vector	p_to_l;
	t_obj		*objs;
	t_vector	intensity;

	intensity = (t_vector){1, 1, 1};
	objs = data->objs;
	while (objs)
	{
		if (objs->light)
		{
			p_to_l = normalize_vect(substract_vect(objs->light->pos, inter));
			p_intensity = add_vect(ambient_lightning_intensity(data), \
				point_intensity(*objs->light, normal_dir, p_to_l, closest));
			l_intensity = add_vect(ambient_lightning_intensity(data), \
				light_intensity(*objs->light));
			intensity = multiply_vect(intensity, \
				divide_vect(p_intensity, l_intensity));
		}
		objs = objs->next;
	}
	return (intensity);
}

/*
 *	Returns the color after applying all light effects on a colored pixel.
*/
t_color	light_effects(t_data *data, t_vector normal, \
	t_closest_obj closest, t_ray ray)
{
	t_color		obj_color;
	t_color		color;
	t_vector	intensity;
	t_vector	normal_dir[2];
	double		shadow;

	obj_color = get_obj_color(closest.obj);
	shadow = shadow_effects(data, intersection_point(ray, \
		closest.distance), closest);
	normal_dir[0] = normal;
	normal_dir[1] = substract_vect((t_vector){0, 0, 0}, ray.dir);
	intensity = light_effects_intensity(data, normal_dir, \
		intersection_point(ray, closest.distance), closest);
	color.r = obj_color.r * intensity.x * shadow;
	color.g = obj_color.g * intensity.y * shadow;
	color.b = obj_color.b * intensity.z * shadow;
	color.sum = color.r + color.g + color.b;
	protect_colors(&color);
	return (color);
}
