/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:30:15 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/26 00:26:09 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the cross product of vector v1 by vector v2.
*/
t_vector	vect_cross_product(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}

/*
 *	Returns the cosinus of the angle formed by two vectors.
*/
double	vect_cos(t_vector v1, t_vector v2)
{
	return (vect_dot(v1, v2) / (vect_length(v1) * vect_length(v2)));
}

/*
 *	Returns the sinus of the angle formed by two vectors.
*/
double	vect_sin(t_vector v1, t_vector v2)
{
	double	sinus;

	sinus = vect_length(vect_cross_product(v1, v2)) \
		/ (vect_length(v1) * vect_length(v2));
	return (sinus);
}

/*
 *	Returns the vector resulting of the rotation of a vector around an axis.
*/
t_vector	rotate_vect(t_vector vector, t_vector axis, double cos, double sin)
{
	t_vector	rotated;

	rotated.x = (axis.x * axis.x * (1 - cos) + cos) * vector.x \
		+ (axis.x * axis.y * (1 - cos) - axis.z * sin) * vector.y \
		+ (axis.x * axis.z * (1 - cos) + axis.y * sin) * vector.z;
	rotated.y = (axis.x * axis.y * (1 - cos) + axis.z * sin) * vector.x \
		+ (axis.y * axis.y * (1 - cos) + cos) * vector.y \
		+ (axis.y * axis.z * (1 - cos) - axis.x * sin) * vector.z;
	rotated.z = (axis.x * axis.z * (1 - cos) - axis.y * sin) * vector.x \
		+ (axis.y * axis.z * (1 - cos) + axis.x * sin) * vector.y \
		+ (axis.z * axis.z * (1 - cos) + cos) * vector.z;
	return (rotated);
}

/*
 *	Changes a base direction, rotating it around its third vector to
 *	match with the given direction.
*/
void	rotate_base(t_vector base[3], t_vector direction)
{
	t_vector	axis;
	double		cos;
	double		sin;

	axis = normalize_vect(vect_cross_product(base[2], direction));
	cos = vect_cos(base[2], direction);
	sin = vect_sin(base[2], direction);
	base[0] = rotate_vect(base[0], axis, cos, sin);
	base[1] = rotate_vect(base[1], axis, cos, sin);
	base[2] = rotate_vect(base[2], axis, cos, sin);
}
