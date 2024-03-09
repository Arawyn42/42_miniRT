/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:33 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/09 18:51:14 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the reflect ratio of an object.
*/
double	get_obj_reflect_ratio(t_obj *obj)
{
	if (obj->pl)
		return (obj->pl->reflect);
	else if (obj->sp)
		return (obj->sp->reflect);
	else if (obj->cy)
		return (obj->cy->reflect);
	return (DEFAULT_REFLECT_RATIO);
}

/*
 *	Returns the direction of the reflected ray.
*/
t_vector	reflection_dir(t_vector normal, t_vector dir)
{
	t_vector	reflection;
	double		scalar;

	scalar = vect_dot(normal, dir);
	reflection.x = 2 * scalar * normal.x - dir.x;
	reflection.y = 2 * scalar * normal.y - dir.y;
	reflection.z = 2 * scalar * normal.z - dir.z;
	return (reflection);
}

/*
 *	Returns the reflection color of a given color according to a reflect ratio.
*/
t_color	reflection_color(t_color color, t_color reflective, double ratio)
{
	t_color	res;
	double	r;

	r = ratio * 0.75;
	res.r = color.r * (1.0 - r) + reflective.r * r;
	res.g = color.g * (1.0 - r) + reflective.g * r;
	res.b = color.b * (1.0 - r) + reflective.b * r;
	protect_colors(&res);
	res.sum = res.r + res.g + res.b;
	return (res);
}
