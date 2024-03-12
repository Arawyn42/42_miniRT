/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arawyn <arawyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:50:50 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/11 17:29:07 by arawyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Sphere struct destroyer.
*/
static void	destroy_one_sphere(t_sphere *sphere)
{
	if (!sphere)
		return ;
	free(sphere);
	sphere = NULL;
}

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
 *	Create, set the values and return sphere struct.
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

static t_sphere	*get_last_sphere(t_sphere *sphere)
{
	if (!sphere)
		return (NULL);
	while (sphere->next)
		sphere = sphere->next;
	return (sphere);
}

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
