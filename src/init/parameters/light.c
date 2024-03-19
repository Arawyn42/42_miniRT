/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:47:09 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/19 04:33:05 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Creates, sets the values and returns a light struct.
*/
t_light	*create_light(t_vector pos, double ratio, int color)
{
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	if (!light)
	{
		print_error("Error: Light: Calloc error.\n");
		return (NULL);
	}
	light->pos = pos;
	light->ratio = ratio;
	light->color = color;
	return (light);
}

/*
 *	Adds a light into the objects list.
*/
void	add_light(t_data *data, t_light *light)
{
	t_obj	*new_obj;
	t_obj	*last_obj;

	new_obj = create_new_obj();
	new_obj->light = light;
	if (!data->objs)
		data->objs = new_obj;
	else
	{
		last_obj = get_last_obj(data->objs);
		last_obj->next = new_obj;
	}
}
