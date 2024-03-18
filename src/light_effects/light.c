/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:25:40 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/17 20:02:50 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the light intensity vector.
*/
t_vector	light_intensity(t_light light)
{
	t_vector	res;
	t_color		l;

	l = int_to_rgb(light.color);
	res.x = light.ratio * l.r / l.sum;
	res.y = light.ratio * l.g / l.sum;
	res.z = light.ratio * l.b / l.sum;
	return (res);
}
