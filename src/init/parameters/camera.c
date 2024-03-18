/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:29:17 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/17 15:14:25 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Camera structure destroyer.
*/
void	destroy_camera(t_camera *camera)
{
	if (!camera)
		return ;
	free(camera);
	camera = NULL;
}

/*
 *	Creates, sets the values and returns a camera structure.
*/
t_camera	*set_camera(t_vector pos, t_vector direction, int fov)
{
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
	{
		print_error("Fatal error: camera struct initialization: ");
		print_error("Out of memory\n");
		return (NULL);
	}
	camera->pos = pos;
	camera->direction = direction;
	camera->fov = fov;
	return (camera);
}
