/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:54:10 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/19 04:36:02 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Creates, sets the values and returns a cylinder structure.
*/
t_cylinder	*create_cylinder(t_vector pos_axis[2], double dhcr[4])
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
	{
		print_error("Error: Cylinder: Calloc error.\n");
		return (NULL);
	}
	cylinder->pos = pos_axis[0];
	cylinder->axis = pos_axis[1];
	cylinder->radius = dhcr[0];
	cylinder->height = dhcr[1];
	cylinder->color = (int)dhcr[2];
	cylinder->reflect = dhcr[3];
	return (cylinder);
}

/*
*	Adds a cylinder into the objects list.
*/
void	add_cylinder(t_data *data, t_cylinder *cylinder)
{
	t_obj		*new_obj;
	t_obj		*last_obj;

	new_obj = create_new_obj();
	new_obj->cy = cylinder;
	if (!data->objs)
		data->objs = new_obj;
	else
	{
		last_obj = get_last_obj(data->objs);
		last_obj->next = new_obj;
	}
}
