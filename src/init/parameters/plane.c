/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:34:37 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/09 18:44:09 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Plane struct destroyer.
*/
static void	destroy_one_plane(t_plane *plane)
{
	if (!plane)
		return ;
	free(plane);
	plane = NULL;
}

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
 *	Create, set the values and return plane struct.
*/
static t_plane	*new_plane(t_vector pos_normal[2], double csr[3])
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
	plane->color = csr[0];
	plane->specular = csr[1];
	plane->reflect = csr[2];
	plane->next = NULL;
	return (plane);
}

static t_plane	*get_last_plane(t_plane *plane)
{
	if (!plane)
		return (NULL);
	while (plane->next)
		plane = plane->next;
	return (plane);
}

void	set_plane(t_plane **plane, t_vector pos_normal[2], double csr[3])
{
	t_plane	*new;
	t_plane	*tmp;

	new = new_plane(pos_normal, csr);
	if (!*plane)
	{
		*plane = new;
		return ;
	}
	tmp = get_last_plane(*plane);
	tmp->next = new;
}
