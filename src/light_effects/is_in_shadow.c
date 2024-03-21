/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:00:20 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/21 14:25:23 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns 1 if the point is in the shadow of an object, 0 if not.
*/
int	is_in_shadow(t_obj *obj, t_vector point, t_light light)
{
	t_ray			p_to_l;
	double			l_distance;
	t_closest_obj	closest;

	p_to_l.origin = point;
	p_to_l.dir = normalize_vect(substract_vect(light.pos, point));
	l_distance = vect_length(substract_vect(light.pos, point));
	closest = closest_intersection(obj, p_to_l);
	if (!closest.obj || closest.obj->pl || closest.obj->light)
		return (0);
	if (closest.distance >= l_distance || is_on_obj(*closest.obj, point))
		return (0);
	return (1);
}
