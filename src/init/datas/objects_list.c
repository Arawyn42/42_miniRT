/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:45:13 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/04 15:00:46 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Destroys one object.
*/
static void	destroy_one_obj(t_obj *obj)
{
	if (!obj)
		return ;
	free(obj);
	obj = NULL;
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
