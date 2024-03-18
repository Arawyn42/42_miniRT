/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:50:50 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/17 15:18:49 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Frees and sets to null a sphere node.
*/
static void	destroy_one_sphere(t_sphere *sphere)
{
	if (!sphere)
		return ;
	free(sphere);
	sphere = NULL;
}

/*
 *	Destroys all spheres and frees the spheres list.
*/
void	destroy_sphere(t_sphere **sphere)
{
	t_sphere	*tmp;

	if (!sphere)
		return ;
	tmp = *sphere;
	while (*sphere)
	{
		tmp = (*sphere)->next;
		destroy_one_sphere(*sphere);
		*sphere = tmp;
	}
	sphere = NULL;
}

/*
 *	Creates, sets the values and returns a sphere structure.
*/
t_sphere	*new_sphere(t_vector pos, double rcr[3])
{
	t_sphere	*sphere;

	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
	{
		print_error("Fatal error: sphere struct initialization: ");
		print_error("Out of memory\n");
		return (NULL);
	}
	sphere->pos = pos;
	sphere->radius = rcr[0];
	sphere->color = (int)rcr[1];
	sphere->reflect = rcr[2];
	sphere->next = NULL;
	return (sphere);
}

/*
 *	Returns the last node of the spheres list.
*/
static t_sphere	*get_last_sphere(t_sphere *sphere)
{
	if (!sphere)
		return (NULL);
	while (sphere->next)
		sphere = sphere->next;
	return (sphere);
}

/*
 *	Adds and sets a sphere at the end of the spheres list.
*/
void	set_sphere(t_sphere **sphere, t_vector pos, double rcr[3])
{
	t_sphere	*new;
	t_sphere	*tmp;

	new = new_sphere(pos, rcr);
	if (!*sphere)
	{
		*sphere = new;
		return ;
	}
	tmp = get_last_sphere(*sphere);
	tmp->next = new;
}
