/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:30:15 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/02 14:30:46 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the cross product of vector v1 by vector v2.
*/
t_point	vect_cross_product(t_point v1, t_point v2)
{
	t_point	res;

	res.x = v2.y * v1.z - v1.y * v2.z;
	res.y = v2.z * v1.x - v1.z * v2.x;
	res.z = v2.x * v1.y - v1.x * v2.y;
	return (res);
}

/*
 *	Returns the cosinus of the angle formed by two vectors.
*/
double	vect_cos(t_point v1, t_point v2)
{
	return (vect_dot(v1, v2) / (vect_length(v1) * vect_length(v2)));
}

/*
 *	Returns the sinus of the angle formed by two vectors.
*/
double	vect_sin(t_point v1, t_point v2)
{
	return (vect_length(vect_cross_product(v1, v2)) \
		/ (vect_length(v1) * vect_length(v2)));
}

/*
 *	Returns the vector resulting of the rotation of a vector around an axis.
*/
t_point	rotate_vect(t_point vector, t_point axis, double cos, double sin)
{
	t_point	rotated;

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
void	rotate_base(t_point base[3], t_point direction)
{
	t_point		axis;
	double		cos;
	double		sin;

	axis = vect_cross_product(normalize_vect(direction), base[2]);
	cos = vect_cos(normalize_vect(direction), base[2]);
	sin = vect_sin(normalize_vect(direction), base[2]);
	base[0] = rotate_vect(base[0], axis, cos, sin);
	base[1] = rotate_vect(base[1], axis, cos, sin);
	base[2] = rotate_vect(base[2], axis, cos, sin);
}
