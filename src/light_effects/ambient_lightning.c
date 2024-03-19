/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:07:33 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/19 05:12:58 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the ambient lightning intensity vector.
*/
t_vector	ambient_lightning_intensity(t_alight a_light)
{
	t_vector	res;
	t_color		al;

	al = int_to_rgb(a_light.color);
	res.x = a_light.ratio * al.r / al.sum;
	res.y = a_light.ratio * al.g / al.sum;
	res.z = a_light.ratio * al.b / al.sum;
	return (res);
}
