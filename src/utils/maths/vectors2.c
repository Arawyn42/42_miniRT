/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 02:58:25 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/02 15:06:42 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Normalizes the vector and return the result.
*/
t_point	normalize_vect(t_point vect)
{
	t_point	normalized;
	double	norm;

	norm = vect_length(vect);
	normalized.x = vect.x / norm;
	normalized.y = vect.y / norm;
	normalized.z = vect.z / norm;
	return (normalized);
}

/*
 *	Divides a vector by another member by member and returns the result.
*/
t_point	divide_vect(t_point	v1, t_point v2)
{
	t_point	res;

	res.x = v1.x / v2.x;
	res.y = v1.y / v2.y;
	res.z = v1.z / v2.z;
	return (res);
}
