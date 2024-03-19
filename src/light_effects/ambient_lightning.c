/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:07:33 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/19 02:59:22 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the ambient lightning intensity vector.
*/
t_vector	ambient_lightning_intensity(t_data *data)
{
	t_vector	res;
	t_color		a_light;

	a_light = int_to_rgb(data->a_light.color);
	res.x = data->a_light.ratio * a_light.r / a_light.sum;
	res.y = data->a_light.ratio * a_light.g / a_light.sum;
	res.z = data->a_light.ratio * a_light.b / a_light.sum;
	return (res);
}
