/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:41:34 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/02 15:31:27 by drenassi         ###   ########.fr       */
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
t_minirt	*init_mem(void)
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
	return (mem);
}
