/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:26:17 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/21 13:23:39 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the diffuse intensity, which is the scalar product between
 *	the vector from light position to the intersection point and
 *	the normal vector at the intersection point.
*/
t_vector	diffuse_intensity(t_vector normal, t_vector p_to_l, t_vector light)
{
	t_vector	diffuse;
	double		ratio;

	ratio = fmax(vect_dot(p_to_l, normal), 0);
	diffuse = multiply_vect_scalar(light, ratio);
	return (diffuse);
}
