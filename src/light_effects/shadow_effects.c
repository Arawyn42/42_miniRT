/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_effects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:16:26 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/18 02:31:15 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns 1 if the point is on the surface of the cone, 0 if not.
*/
int	is_on_cone(t_cone co, t_vector p)
{
	t_vector	c;
	double		dist;
	double		disk_dist;

	c = add_vect(co.pos, multiply_vect_scalar(co.axis, co.height));
	if (fabs(vect_dot(substract_vect(c, p), co.axis)) < PRECISION \
		&& vect_length(substract_vect(c, p)) <= co.radius)
		return (1);
	dist = vect_dot(substract_vect(p, co.pos), co.axis);
	if (dist <= 0 || dist > co.height)
		return (0);
	disk_dist = vect_length(substract_vect(substract_vect(p, co.pos), \
		multiply_vect_scalar(co.axis, dist)));
	if (disk_dist <= dist * co.radius / co.height + PRECISION)
		return (1);
	return (0);
}

/*
 *	Returns the hard shadow intensity.
*/
double	shadow_effects(t_data *data, t_vector inter, t_closest_obj closest)
{
	t_light	*light;
	double	shadow;
	double	max_shadow;

	shadow = 1;
	max_shadow = 1;
	light = data->light;
	while (light)
	{
		if (is_in_shadow(data, inter, *light))
			shadow = fmin(fmax(0.6, (1 - light->ratio)) * fmin(1 + closest.reflect, 1.55), 1);
		if (shadow < max_shadow)
		{
			if (max_shadow == 1)
				max_shadow = shadow;
			else
				max_shadow = (shadow + max_shadow) / 2;
		}
		light = light->next;
	}
	return (max_shadow);
}
