/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:50:50 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/19 04:34:48 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Creates, sets the values and returns a sphere structure.
*/
t_sphere	*create_sphere(t_vector pos, double rcr[3])
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
	{
		print_error("Error: Sphere: Calloc error.\n");
		return (NULL);
	}
	sphere->pos = pos;
	sphere->radius = rcr[0];
	sphere->color = (int)rcr[1];
	sphere->reflect = rcr[2];
	return (sphere);
}

/*
*	Adds a sphere into the objects list.
*/
void	add_sphere(t_data *data, t_sphere *sphere)
{
	t_obj		*new_obj;
	t_obj		*last_obj;

	new_obj = create_new_obj();
	new_obj->sp = sphere;
	if (!data->objs)
		data->objs = new_obj;
	else
	{
		last_obj = get_last_obj(data->objs);
		last_obj->next = new_obj;
	}
}
