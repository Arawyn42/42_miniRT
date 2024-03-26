/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:54:49 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/25 21:04:29 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	matrix_det(t_vector m[3])
{
	return (m[0].x * m[1].y * m[2].z \
	+ m[0].y * m[1].z * m[2].x \
	+ m[0].z * m[1].x * m[2].y \
	- m[0].z * m[1].y * m[2].x \
	- m[0].y * m[1].x * m[2].z \
	- m[0].x * m[1].z * m[2].y);
}

t_vector	multiply_vect_matrix(t_vector v, t_vector m[3])
{
	return ((t_vector){v.x * m[0].x + v.y * m[1].x + v.z * m[2].x, \
	v.x * m[0].y + v.y * m[1].y + v.z * m[2].y, \
	v.x * m[0].z + v.y * m[1].z + v.z * m[2].z});
}

void	transpose_matrix(t_vector m[3])
{
	t_vector	m0;
	t_vector	m1;
	t_vector	m2;

	m0 = (t_vector){m[0].x, m[1].x, m[2].x};
	m1 = (t_vector){m[0].y, m[1].y, m[2].y};
	m2 = (t_vector){m[0].z, m[1].z, m[2].z};
	m[0] = m0;
	m[1] = m1;
	m[2] = m2;
}

void	inverse_matrix(t_vector m[3])
{
	double	det;
	t_vector	m0;
	t_vector	m1;
	t_vector	m2;

	m0 = (t_vector){m[0].x, m[0].y, m[0].z};
	m1 = (t_vector){m[1].x, m[1].y, m[1].z};
	m2 = (t_vector){m[2].x, m[2].y, m[2].z};
	det = matrix_det(m);
	m[0].x = (m1.y * m2.z - m1.z * m2.y) / det;
	m[0].y = (m1.z * m2.x - m1.x * m2.z) / det;
	m[0].z = (m1.x * m2.y - m1.y * m2.x) / det;
	m[1].x = (m0.z * m2.y - m0.y * m2.z) / det;
	m[1].y = (m0.x * m2.z - m0.z * m2.x) / det;
	m[1].z = (m0.y * m2.x - m0.x * m2.y) / det;
	m[2].x = (m0.y * m1.z - m0.z * m1.y) / det;
	m[2].y = (m0.z * m1.x - m0.x * m1.z) / det;
	m[2].z = (m0.x * m1.y - m0.y * m1.x) / det;
}
