/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:34:37 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/17 15:17:14 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Frees and sets to null a plane node.
*/
static void	destroy_one_plane(t_plane *plane)
{
	if (!plane)
		return ;
	free(plane);
	plane = NULL;
}

/*
 *	Destroys all planes and frees the planes list.
*/
void	destroy_plane(t_plane **plane)
{
	t_plane	*tmp;

	if (!plane || !(*plane))
		return ;
	tmp = *plane;
	while (*plane)
	{
		tmp = (*plane)->next;
		destroy_one_plane(*plane);
		*plane = tmp;
	}
	plane = NULL;
}

/*
 *	Creates, sets the values and returns a plane structure.
*/
static t_plane	*new_plane(t_vector pos_normal[2], double cr[2])
{
	t_plane	*plane;

	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
	{
		print_error("Fatal error: plane struct initialization: ");
		print_error("Out of memory\n");
		return (NULL);
	}
	plane->pos = pos_normal[0];
	plane->normal = pos_normal[1];
	plane->color = cr[0];
	plane->reflect = cr[1];
	plane->next = NULL;
	return (plane);
}

/*
 *	Returns the last node of the planes list.
*/
static t_plane	*get_last_plane(t_plane *plane)
{
	if (!plane)
		return (NULL);
	while (plane->next)
		plane = plane->next;
	return (plane);
}

/*
 *	Adds and sets a plane at the end of the planes list.
*/
void	set_plane(t_plane **plane, t_vector pos_normal[2], double cr[2])
{
	t_plane	*new;
	t_plane	*tmp;

	new = new_plane(pos_normal, cr);
	if (!*plane)
	{
		*plane = new;
		return ;
	}
	tmp = get_last_plane(*plane);
	tmp->next = new;
}
