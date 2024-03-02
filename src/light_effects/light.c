/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:25:40 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/02 14:21:56 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the light intensity vector.
*/
t_point	light_intensity(t_data *data)
{
	t_point	res;
	t_color	light;

	light = int_to_rgb(data->light->color);
	res.x = data->light->ratio * light.r / light.sum;
	res.y = data->light->ratio * light.g / light.sum;
	res.z = data->light->ratio * light.b / light.sum;
	return (res);
}