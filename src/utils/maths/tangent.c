/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tangent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:25:57 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/26 18:17:32 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns a tangent vector of a sphere.
*/
t_vector	sphere_tangent(double radius, double theta, double phi)
{
	t_vector	tangent;

	tangent.x = -radius * sin(phi) * sin(theta);
	tangent.y = 0;
	tangent.z = radius * sin(phi) * cos(theta);
	tangent = normalize_vect(tangent);
	return (tangent);
}

t_vector	cylinder_tangent(t_cylinder cylinder, t_vector point, double theta)
{
	t_vector	cy_to_p;
	t_vector	n;
	double		scalar;

	cy_to_p = substract_vect(point, cylinder.pos);
	scalar = vect_dot(cy_to_p, cylinder.axis);
	if (fabs(scalar) < PRECISION ||  scalar > cylinder.height - PRECISION)
	{
		n = substract_vect(cy_to_p, multiply_vect_scalar(cylinder.axis, \
			vect_dot(cy_to_p, cylinder.axis)));
		return (normalize_vect(n));
	}
	n = (t_vector){-cylinder.radius * sin(theta), 0, \
		cylinder.radius * cos(theta)};
	return (normalize_vect(n));
}

t_vector	cone_tangent(t_cone cone, t_vector point, double theta)
{
	t_vector	co_to_p;
	t_vector	n;
	double		radius;

	co_to_p = substract_vect(point, cone.pos);
	if (fabs(vect_dot(co_to_p, cone.axis)) < PRECISION)
		return (normalize_vect(co_to_p));
	radius = vect_length(substract_vect(co_to_p, multiply_vect_scalar(cone.axis, vect_dot(co_to_p, cone.axis))));
	n = (t_vector){-radius * sin(theta), 0, \
		cone.radius * cos(theta)};
	return (normalize_vect(n));
}
