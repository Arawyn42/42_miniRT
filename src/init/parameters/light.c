/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:47:09 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/09 15:05:46 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Light struct destroyer.
*/
void	destroy_light(t_light *light)
{
	if (!light)
		return ;
	free(light);
	light = NULL;
}

/*
 *	Create, set the values and return light struct.
*/
t_light	*set_light(t_point pos, double ratio, int color)
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
	return (light);
}
