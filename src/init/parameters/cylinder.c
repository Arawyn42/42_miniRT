/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:54:10 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/09 18:03:28 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Cylinder struct destroyer.
*/
static void	destroy_one_cylinder(t_cylinder *cylinder)
{
	if (!cylinder)
		return ;
	free(cylinder);
	cylinder = NULL;
}

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
 *	Create, set the values and return cylinder struct.
*/
static t_cylinder	*new_cylinder(t_vector pos_axis[2], double dhcsr[5])
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
	cylinder->radius = dhcsr[0];
	cylinder->height = dhcsr[1];
	cylinder->color = (int)dhcsr[2];
	cylinder->specular = dhcsr[3];
	cylinder->reflect = dhcsr[4];
	cylinder->next = NULL;
	return (cylinder);
}

static t_cylinder	*get_last_cylinder(t_cylinder *cylinder)
{
	if (!cylinder)
		return (NULL);
	while (cylinder->next)
		cylinder = cylinder->next;
	return (cylinder);
}

void	set_cylinder(t_cylinder **cylinder, t_vector pos_axis[2], \
	double dhcsr[5])
{
	t_cylinder	*new;
	t_cylinder	*tmp;

	new = new_cylinder(pos_axis, dhcsr);
	if (!*cylinder)
	{
		*cylinder = new;
		return ;
	}
	tmp = get_last_cylinder(*cylinder);
	tmp->next = new;
}
