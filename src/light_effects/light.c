/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:25:40 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/16 10:31:38 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the light intensity vector.
*/
t_vector	light_intensity(t_data *data, t_light light)
{
	t_vector	res;
	t_color		l;

	l = int_to_rgb(light.color);
	res.x = data->light->ratio * l.r / l.sum;
	res.y = data->light->ratio * l.g / l.sum;
	res.z = data->light->ratio * l.b / l.sum;
	return (res);
}
