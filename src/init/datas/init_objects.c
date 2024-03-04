/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:52:51 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/04 15:38:23 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Adds all planes in objects list.
*/
static void	init_objs_pl(t_data *data)
{
	t_plane		*pl;
	t_obj		*new_obj;
	t_obj		*last_obj;

	pl = data->planes;
	while (pl)
	{
		new_obj = create_new_obj();
		new_obj->pl = pl;
		if (!data->objs)
			data->objs = new_obj;
		else
		{
			last_obj = get_last_obj(data->objs);
			last_obj->next = new_obj;
		}
		pl = pl->next;
	}
}

/*
*	Adds all spheres in objects list.
*/
static void	init_objs_sp(t_data *data)
{
	t_sphere	*sp;
	t_obj		*new_obj;
	t_obj		*last_obj;

	sp = data->spheres;
	while (sp)
	{
		new_obj = create_new_obj();
		new_obj->sp = sp;
		if (!data->objs)
			data->objs = new_obj;
		else
		{
			last_obj = get_last_obj(data->objs);
			last_obj->next = new_obj;
		}
		sp = sp->next;
	}
}


/*
*	Adds all cylinders in objects list.
*/
static void	init_objs_cy(t_data *data)
{
	t_cylinder	*cy;
	t_obj		*new_obj;
	t_obj		*last_obj;

	cy = data->cylinders;
	while (cy)
	{
		new_obj = create_new_obj();
		new_obj->cy = cy;
		if (!data->objs)
			data->objs = new_obj;
		else
		{
			last_obj = get_last_obj(data->objs);
			last_obj->next = new_obj;
		}
		cy = cy->next;
	}
}

/*
 *	Creates light object and adds it to the objects list.
*/
static void	init_objs_light(t_data *data)
{
	t_obj	*new_obj;
	t_obj	*last_obj;

	new_obj = create_new_obj();
	new_obj->light = data->light;
	if (!data->objs)
		data->objs = new_obj;
	else
	{
		last_obj = get_last_obj(data->objs);
		last_obj->next = new_obj;	
	}
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
