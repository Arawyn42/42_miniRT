/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tangent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:25:57 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/25 23:32:12 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	sphere_tangent(double radius, double theta, double phi)
{
	t_vector	tangent;

	tangent.x = -radius * sin(phi) * sin(theta);
	tangent.y = 0;
	tangent.z = radius * sin(phi) * cos(theta);
	tangent = normalize_vect(tangent);
	return (tangent);
}
