/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:07:33 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/21 14:41:00 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the ambient lightning intensity vector according to the ambient
 *	surface reflection property of the object material.
*/
t_vector	ambient_lightning_intensity(t_alight a_light, double property)
{
	t_vector	intensity;
	t_color		al;

	al = int_to_rgb(a_light.color);
	intensity.x = property * 3 * a_light.ratio * al.r / al.sum;
	intensity.y = property * 3 * a_light.ratio * al.g / al.sum;
	intensity.z = property * 3 * a_light.ratio * al.b / al.sum;
	return (intensity);
}
