/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:25:40 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/21 14:42:27 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the light intensity vector according to the lambertian surface
 *	reflection property of the object material.
*/
t_vector	light_intensity(t_light light, double lambertian)
{
	t_vector	res;
	t_color		l;

	l = int_to_rgb(light.color);
	res.x = lambertian * 3 * light.ratio * l.r / l.sum;
	res.y = lambertian * 3 * light.ratio * l.g / l.sum;
	res.z = lambertian * 3 * light.ratio * l.b / l.sum;
	return (res);
}
