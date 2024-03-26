/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:50:50 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/25 23:09:41 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Creates, sets the values and returns a sphere structure.
*/
t_sphere	*create_sphere(t_vector pos, double rcr[3], char *map[2])
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
	sphere->base[0] = (t_vector){1, 0, 0};
	sphere->base[1] = (t_vector){0, 1, 0};
	sphere->base[2] = (t_vector){0, 0, 1};
	sphere->normal_map = create_map(map[0]);
	sphere->texture = create_map(map[1]);
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
