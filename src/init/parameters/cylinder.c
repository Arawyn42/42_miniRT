/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:54:10 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/17 15:16:12 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Frees and sets to null a cylinder node.
*/
static void	destroy_one_cylinder(t_cylinder *cylinder)
{
	if (!cylinder)
		return ;
	free(cylinder);
	cylinder = NULL;
}

/*
 *	Destroys all cylinders and frees the cylinders list.
*/
void	destroy_cylinder(t_cylinder **cylinder)
{
	t_cylinder	*tmp;

	if (!cylinder)
		return ;
	tmp = *cylinder;
	while (*cylinder)
	{
		tmp = (*cylinder)->next;
		destroy_one_cylinder(*cylinder);
		*cylinder = tmp;
	}
	cylinder = NULL;
}

/*
 *	Creates, sets the values and returns a cylinder structure.
*/
static t_cylinder	*new_cylinder(t_vector pos_axis[2], double dhcr[4])
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
	{
		print_error("Fatal error: cylinder struct initialization: ");
		print_error("Out of memory\n");
		return (NULL);
	}
	cylinder->pos = pos_axis[0];
	cylinder->axis = pos_axis[1];
	cylinder->radius = dhcr[0];
	cylinder->height = dhcr[1];
	cylinder->color = (int)dhcr[2];
	cylinder->reflect = dhcr[3];
	cylinder->next = NULL;
	return (cylinder);
}

/*
 *	Returns the last node of the cylinders list.
*/
static t_cylinder	*get_last_cylinder(t_cylinder *cylinder)
{
	if (!cylinder)
		return (NULL);
	while (cylinder->next)
		cylinder = cylinder->next;
	return (cylinder);
}

/*
 *	Adds and sets a cylinder at the end of the cylinders list.
*/
void	set_cylinder(t_cylinder **cylinder, t_vector pos_axis[2], \
	double dhcr[4])
{
	t_cylinder	*new;
	t_cylinder	*tmp;

	new = new_cylinder(pos_axis, dhcr);
	if (!*cylinder)
	{
		*cylinder = new;
		return ;
	}
	tmp = get_last_cylinder(*cylinder);
	tmp->next = new;
}
