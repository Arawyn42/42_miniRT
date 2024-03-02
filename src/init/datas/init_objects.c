/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:52:51 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/02 15:17:13 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Fills all planes in objects list.
*/
static void	init_objs_pl(t_data *data)
{
	t_plane	*pl;

	pl = data->planes;
	while (pl)
	{
		set_objs(&data->objs, pl, NULL, NULL);
		pl = pl->next;
	}
}

/*
*	Fills all spheres in objects list.
*/
static void	init_objs_sp(t_data *data)
{
	t_sphere	*sp;

	sp = data->spheres;
	while (sp)
	{
		set_objs(&data->objs, NULL, sp, NULL);
		sp = sp->next;
	}
}

/*
*	Fills all cylinders in objects list.
*/
static void	init_objs_cy(t_data *data)
{
	t_cylinder	*cy;

	cy = data->cylinders;
	while (cy)
	{
		set_objs(&data->objs, NULL, NULL, cy);
		cy = cy->next;
	}
}

/*
 *	Creates light object and adds it to the objects list.
*/
static void	init_objs_light(t_data *data)
{
	t_obj	*light_obj;
	t_obj	*last;

	last = data->objs;
	while (last->next)
		last = last->next;
	light_obj = ft_calloc(1, sizeof(t_obj));
	if (!light_obj)
	{
		print_error("Fatal error: obj struct initialization: ");
		print_error("Out of memory\n");
		return ;
	}
	light_obj->pl = NULL;
	light_obj->sp = NULL;
	light_obj->cy = NULL;
	light_obj->light = data->light;
	light_obj->next = NULL;
	last->next = light_obj;
}

/*
*	Initializes the objects list.
*/
void	init_objs(t_data *data)
{
	data->objs = NULL;
	if (data->planes)
		init_objs_pl(data);
	if (data->spheres)
		init_objs_sp(data);
	if (data->cylinders)
		init_objs_cy(data);
	if (data->light)
		init_objs_light(data);
}
