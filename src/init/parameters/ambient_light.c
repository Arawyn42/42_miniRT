/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:59:15 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/02 15:35:37 by drenassi         ###   ########.fr       */
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
 *	Create, set the values and return ambient lightning struct.
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