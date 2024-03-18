/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:07:56 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/17 16:52:15 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Frees and sets to null a cone node.
*/
static void	destroy_one_cone(t_cone *cone)
{
	if (!cone)
		return ;
	free(cone);
	cone = NULL;
}

/*
 *	Destroys all conees and frees the conees list.
*/
void	destroy_cone(t_cone **cone)
{
	t_cone	*tmp;

	if (!cone || !(*cone))
		return ;
	tmp = *cone;
	while (*cone)
	{
		tmp = (*cone)->next;
		destroy_one_cone(*cone);
		*cone = tmp;
	}
	cone = NULL;
}

/*
 *	Creates, sets the values and return a cone structure.
*/
static t_cone	*new_cone(t_vector pos_axis[2], double rhcr[4])
{
	t_cone	*cone;

	cone = ft_calloc(1, sizeof(t_cone));
	if (!cone)
	{
		print_error("Fatal error: cone struct initialization: ");
		print_error("Out of memory\n");
		return (NULL);
	}
	cone->pos = pos_axis[0];
	cone->axis = pos_axis[1];
	cone->radius = rhcr[0];
	cone->height = rhcr[1];
	cone->color = rhcr[2];
	cone->reflect = rhcr[3];
	cone->next = NULL;
	return (cone);
}

/*
 *	Returns the last node of the conees list.
*/
static t_cone	*get_last_cone(t_cone *cone)
{
	if (!cone)
		return (NULL);
	while (cone->next)
		cone = cone->next;
	return (cone);
}

/*
 *	Adds and sets a cone at the end of the conees list.
*/
void	set_cone(t_cone **cone, t_vector pos_axis[2], double rhcr[4])
{
	t_cone	*new;
	t_cone	*tmp;

	new = new_cone(pos_axis, rhcr);
	if (!*cone)
	{
		*cone = new;
		return ;
	}
	tmp = get_last_cone(*cone);
	tmp->next = new;
}
