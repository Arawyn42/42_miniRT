/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:25:07 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/17 20:50:44 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Adds all cones in objects list.
*/
void	init_objs_cone(t_data *data)
{
	t_cone		*cones;
	t_obj		*new_obj;
	t_obj		*last_obj;

	cones = data->cones;
	while (cones)
	{
		new_obj = create_new_obj();
		new_obj->co = cones;
		if (!data->objs)
			data->objs = new_obj;
		else
		{
			last_obj = get_last_obj(data->objs);
			last_obj->next = new_obj;
		}
		cones = cones->next;
	}
}
