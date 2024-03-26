/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:45:13 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/26 14:31:23 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Second part of the destroy_one_obj function.
*/
static void	destroy_one_obj2(t_obj *obj)
{
	if (obj->co)
	{
		destroy_map(&obj->co->normal_map);
		destroy_map(&obj->co->texture);
		free (obj->co);
	}
	free(obj);
	obj = NULL;
}

/*
*	Destroys one object.
*/
static void	destroy_one_obj(t_obj *obj)
{
	if (!obj)
		return ;
	if (obj->light)
		free (obj->light);
	if (obj->pl)
	{
		destroy_map(&obj->pl->normal_map);
		destroy_map(&obj->pl->texture);
		free (obj->pl);
	}
	if (obj->sp)
	{
		destroy_map(&obj->sp->normal_map);
		destroy_map(&obj->sp->texture);
		free (obj->sp);
	}
	if (obj->cy)
	{
		destroy_map(&obj->cy->normal_map);
		destroy_map(&obj->cy->texture);
		free (obj->cy);
	}
	destroy_one_obj2(obj);
}

/*
*	Destroy all objects in objects list.
*/
void	destroy_objs(t_obj **obj)
{
	t_obj	*tmp;

	if (!obj)
		return ;
	tmp = *obj;
	while (*obj)
	{
		tmp = (*obj)->next;
		destroy_one_obj(*obj);
		*obj = tmp;
	}
	obj = NULL;
}

/*
 *	Creates a new object and initializes its fields to NULL;
*/
t_obj	*create_new_obj(void)
{
	t_obj	*new;

	new = ft_calloc(1, sizeof(t_obj));
	if (!new)
		return (NULL);
	new->pl = NULL;
	new->sp = NULL;
	new->cy = NULL;
	new->co = NULL;
	new->light = NULL;
	new->next = NULL;
	return (new);
}

/*
*	Returns the last object of the objects list.
*/
t_obj	*get_last_obj(t_obj *obj)
{
	if (!obj)
		return (NULL);
	while (obj->next)
		obj = obj->next;
	return (obj);
}
