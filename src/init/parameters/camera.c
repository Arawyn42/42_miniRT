/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:29:17 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/25 15:30:11 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Creates, sets the values and returns a camera structure.
*/
t_camera	set_camera(t_vector pos, t_vector direction, int fov)
{
	t_camera	camera;

	camera.pos = pos;
	camera.direction = normalize_vect(direction);
	camera.fov = fov;
	camera.base[0] = (t_vector){1, 0, 0};
	camera.base[1] = (t_vector){0, 1, 0};
	camera.base[2] = (t_vector){0, 0, 1};
	return (camera);
}
