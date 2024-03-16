/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:47:09 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/16 10:06:24 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Light struct destroyer.
*/
static void	destroy_one_light(t_light *light)
{
	if (!light)
		return ;
	free(light);
	light = NULL;
}

/*
 *	Lights struct destroyer.
*/
void	destroy_lights(t_light **light)
{
	t_light	*tmp;

	if (!light || !(*light))
		return ;
	tmp = *light;
	while (*light)
	{
		tmp = (*light)->next;
		destroy_one_light(*light);
		*light = tmp;
	}
	light = NULL;
}

/*
 *	Create, set the values and return light struct.
*/
static t_light	*new_light(t_vector pos, double ratio, int color)
{
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	if (!light)
	{
		print_error("Fatal error: light struct initialization: ");
		print_error("Out of memory\n");
		return (NULL);
	}
	light->pos = pos;
	light->ratio = ratio;
	light->color = color;
	light->next = NULL;
	return (light);
}

static t_light	*get_last_light(t_light *light)
{
	if (!light)
		return (NULL);
	while (light->next)
		light = light->next;
	return (light);
}

/*
 *	Creates, sets the values and returns light struct.
*/
void	set_light(t_light **light, t_vector pos, double ratio, int color)
{
	t_light	*new;
	t_light	*tmp;

	new = new_light(pos, ratio, color);
	if (!*light)
	{
		*light = new;
		return ;
	}
	tmp = get_last_light(*light);
	tmp->next = new;
}
