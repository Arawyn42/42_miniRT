/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:41:34 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/18 21:18:00 by drenassi         ###   ########.fr       */
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
	if (mem->win)
	{
		destroy_image(mem->img, mem->win->mlx);
		destroy_window(mem->win);
	}
	if (mem->data)
		destroy_data(mem->data);
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
	mem->img = NULL;
	mem->win = NULL;
	mem->data = NULL;
	mem->base[0] = (t_vector){1, 0, 0};
	mem->base[1] = (t_vector){0, 1, 0};
	mem->base[2] = (t_vector){0, 0, 1};
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
	mem->win = get_window();
	if (!mem->win)
		exit_handling(mem);
	mem->img = get_image(mem->win);
	if (!mem->img)
		exit_handling(mem);
	mem->data = set_data(file);
	mem->vp = init_viewport(mem->data->camera->fov, VIEWPORT_DIST);
	return (mem);
}
