/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_effects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:20:04 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/21 15:13:20 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Applies diffuse intensity and specular intensity on light ratio
 *	and returns the resulting light intensity as a vector.
*/
static t_vector	point_intensity(t_light light, t_vector normal, t_vector p_to_l)
{
	t_vector	intensity;
	t_vector	l_intensity;
	t_vector	diffuse;
	t_vector	specular;

	l_intensity = light_intensity(light, 0.8);
	diffuse = diffuse_intensity(normal, p_to_l, l_intensity);
	specular = specular_intensity(p_to_l, normal, l_intensity);
	intensity = add_vect(diffuse, specular);
	return (intensity);
}

/*
*	Returns the light intensity vector after applying the ambient
*	lightning ratio on the diffuse intensity and on the specular
*	intensity.
*/
static t_vector	light_effects_intensity(t_data *data, \
	t_vector normal, t_vector point, t_closest_obj current)
{
	t_vector	intensity;
	t_vector	p_intensity;
	t_vector	p_to_l;
	t_obj		*objs;

	intensity = ambient_lightning_intensity(data->a_light, 0.8);
	objs = data->objs;
	while (objs)
	{
		if (objs->light)
		{
			p_to_l = normalize_vect(substract_vect(objs->light->pos, point));
			p_intensity = point_intensity(*objs->light, normal, p_to_l);
			if (is_in_shadow(current.obj, point, *objs->light))
				p_intensity = multiply_vect_scalar(p_intensity, 0.2);
			intensity = add_vect(intensity, p_intensity);
		}
		objs = objs->next;
	}
	return (intensity);
}

/*
 *	Returns the color after applying all light effects on a colored pixel.
*/
t_color	light_effects(t_data *data, t_vector normal, \
	t_closest_obj current, t_ray ray)
{
	t_color		obj_color;
	t_color		color;
	t_vector	intensity;

	obj_color = get_obj_color(current.obj);
	intensity = light_effects_intensity(data, normal, \
		intersection_point(ray, current.distance), current);
	color.r = obj_color.r * (intensity.x);
	color.g = obj_color.g * (intensity.y);
	color.b = obj_color.b * (intensity.z);
	color.sum = color.r + color.g + color.b;
	protect_colors(&color);
	return (color);
}
