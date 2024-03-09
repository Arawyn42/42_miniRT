/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_effects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:20:04 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/09 15:09:35 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the diffuse intensity, which is the scalar product between
 *	the vector from light position to the intersection point and
 *	the normal vector at the intersection point.
*/
static double	diffuse_intensity(t_point normal, t_point p_to_l)
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
static double	specular_intensity(t_point p_to_l, t_point normal, \
	t_point dir, double power)
{
	t_point		reflect;
	double		scalar;

	if (power < PRECISION)
		return (0);
	reflect = reflection_dir(normal, p_to_l);
	scalar = vect_dot(reflect, dir);
	if (scalar > 0)
		return (pow(scalar, power));
	return (0);
}

/*
 *	Applies diffuse intensity and specular intensity on light ratio
 *	and returns the resulting light intensity as a vector.
*/
static t_point	point_intensity(t_light light, t_point normal, \
	t_point p_to_l, t_point dir)
{
	t_point	intensity;
	t_color	light_color;
	double	ratio;

	light_color = int_to_rgb(light.color);
	ratio = light.ratio * (diffuse_intensity(normal, p_to_l) \
		+ specular_intensity(p_to_l, normal, dir, SPECULAR_POWER));
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
static t_point	light_effects_intensity(t_data *data, \
	t_point normal, t_point inter, t_point dir)
{
	t_point			a_light;
	t_point			p_intensity;
	t_point			l_intensity;
	t_point			p_to_l;
	t_obj			*objs;

	a_light = ambient_lightning_intensity(data);
	objs = data->objs;
	while (objs)
	{
		if (objs->light)
		{
			p_to_l = normalize_vect(substract_vect(objs->light->pos, inter));
			p_intensity = add_vect(a_light, \
				point_intensity(*objs->light, normal, p_to_l, dir));
			l_intensity = add_vect(a_light, light_intensity(data));
			return (divide_vect(p_intensity, l_intensity));
		}
		objs = objs->next;
	}
	return ((t_point){1, 1, 1});
}

double is_in_shadow(t_data *data, t_point inter, t_obj	*obj)
{
	t_ray	p_to_l;
	t_closest_obj	closest;

	p_to_l.origin = inter;
	p_to_l.dir = normalize_vect(substract_vect(inter, data->light->pos));
	closest = closest_intersection(p_to_l, data->objs);
	if (!closest.obj || closest.obj == obj)
		return (1);
	return (1);
}

/*
 *	Returns the color after applying all light effects on a colored pixel.
*/
t_color	light_effects(t_data *data, t_point normal, \
	t_closest_obj closest, t_ray ray)
{
	t_color	obj_color;
	t_color	color;
	t_point	intensity;
	t_point	inter;
	double	shadow;

	inter = intersection_point(ray, closest.distance);
	obj_color = get_obj_color(closest.obj);
	intensity = light_effects_intensity(data, normal, inter, \
		substract_vect((t_point){0, 0, 0}, ray.dir));
	shadow = is_in_shadow(data, inter, closest.obj);
	color.r = obj_color.r * intensity.x * shadow;
	color.g = obj_color.g * intensity.y * shadow;
	color.b = obj_color.b * intensity.z * shadow;
	color.sum = color.r + color.g + color.b;
	protect_colors(&color);
	return (color);
}
