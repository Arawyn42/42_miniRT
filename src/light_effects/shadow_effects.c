/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_effects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:16:26 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/17 14:23:19 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
