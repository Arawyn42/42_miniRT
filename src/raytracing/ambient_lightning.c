/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:07:33 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/01 23:25:27 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	ambient_lightning_intensity(t_data *data)
{
	t_point	res;
	t_color	a_light;

	if (!data->a_light)
		return ((t_point){1, 1, 1});
	a_light = int_to_rgb(data->a_light->color);
	res.x = data->a_light->ratio * a_light.r / a_light.sum;
	res.y = data->a_light->ratio * a_light.g / a_light.sum;
	res.z = data->a_light->ratio * a_light.b / a_light.sum;
	return (res);
}
