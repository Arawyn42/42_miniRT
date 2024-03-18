/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:59:15 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/17 15:14:17 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Ambient lightning struct destroyer.
*/
void	destroy_alight(t_alight *alight)
{
	if (!alight)
		return ;
	free(alight);
	alight = NULL;
}

/*
 *	Creates, sets the values and returns an ambient lightning structure.
*/
t_alight	*set_alight(double ratio, int color)
{
	t_alight	*alight;

	alight = ft_calloc(1, sizeof(t_alight));
	if (!alight)
	{
		print_error("Fatal error: ambient lightning struct initialization: ");
		print_error("Out of memory\n");
		return (NULL);
	}
	alight->ratio = ratio;
	alight->color = color;
	return (alight);
}
