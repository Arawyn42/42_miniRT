/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:41:34 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/25 15:32:12 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Frees all structures then exits the program.
*/
int	exit_handling(t_minirt *mem)
{
	if (!mem)
		exit(EXIT_FAILURE);
	destroy_image(&mem->img, mem->win.mlx);
	destroy_window(&mem->win);
	destroy_data(&mem->data);
	free(mem);
	exit(EXIT_SUCCESS);
}

/*
 *	Inits a memory structure and returns it.
*/
static t_minirt	*init_mem(void)
{
	t_minirt	*mem;

	mem = malloc(sizeof(t_minirt));
	if (!mem)
	{
		print_error("Fatal error: mem initialization: Out of memory\n");
		exit_handling(mem);
	}
	mem->start = (t_vector){-SCREEN_W / 2, -SCREEN_H / 2, 0};
	mem->end = (t_vector){SCREEN_W / 2, SCREEN_H / 2, 0};
	return (mem);
}

/*
 *	Sets all datas and creates the miniRT's window.
*/
t_minirt	*set_minirt(char *file)
{
	t_minirt	*mem;

	mem = init_mem();
	if (!init_window(&mem->win))
		return (NULL);
	if (!init_image(&mem->img, mem->win))
		return (NULL);
	mem->data = set_data(file);
	mem->vp = init_viewport(mem->data.camera.fov, VIEWPORT_DIST);
	return (mem);
}
