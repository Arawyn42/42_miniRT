/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:27:59 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/21 15:25:04 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the specular intensity, which is the scalar product between
 *	the reflection vector and the vector from light position to the
 *	intersection point.
*/
t_vector	specular_intensity(t_vector p_to_l, t_vector normal, t_vector light)
{
	t_vector	specular;
	double		scalar;
	double		power;
	double		property;

	specular = light;
	power = 60;
	property = 0.4;
	scalar = fmax(vect_dot(p_to_l, normal), 0);
	specular = multiply_vect_scalar(specular, pow(scalar, power) * property);
	return (specular);
}
