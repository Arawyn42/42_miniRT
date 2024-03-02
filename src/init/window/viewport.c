/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:23:08 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/02 00:14:12 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
*	Initializes the viewport in function of the horizontal FOV and the
*	distance from the camera's origin.
*/
t_viewport	init_viewport(double fov, double distance)
{
	t_viewport	vp;

	vp.w = fabs(2 * distance * tan(fov * (M_PI / 180) / 2));
	vp.w_ratio = vp.w / SCREEN_W;
	vp.h = vp.w_ratio * SCREEN_H;
	vp.h_ratio = vp.h / SCREEN_H;
	return (vp);
}
