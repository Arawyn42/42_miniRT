/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:55:33 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/27 19:00:48 by drenassi         ###   ########.fr       */
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
	else if (obj->co)
		return (obj->co->reflect);
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
	reflection = substract_vect(multiply_vect_scalar(normal, 2 * scalar), dir);
	return (reflection);
}

/*
 *	Returns the reflection color of a given color according to a reflect ratio.
*/
t_color	reflection_color(t_color color, t_color reflective, \
		double ratio, double cap)
{
	t_color	res;
	double	r;

	if (cap > 1)
		cap = 1;
	else if (cap < 0)
		cap = 0;
	r = ratio * cap;
	res.r = color.r * (1.0 - r) + reflective.r * r;
	res.g = color.g * (1.0 - r) + reflective.g * r;
	res.b = color.b * (1.0 - r) + reflective.b * r;
	protect_colors(&res);
	res.sum = res.r + res.g + res.b;
	return (res);
}
