/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:42:59 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/19 03:37:54 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_image(t_image *img, void *mlx)
{
	if (mlx && img->image)
		mlx_destroy_image(mlx, img->image);
}

int	init_image(t_image *img, t_window win)
{
	img->image = mlx_new_image(win.mlx, SCREEN_W, SCREEN_H);
	if (!img->image)
	{
		print_error("Fatal error: Image initialization failed\n");
		return (destroy_image(img, win.mlx), 0);
	}
	img->addr = mlx_get_data_addr(img->image, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	if (!img->addr)
	{
		print_error("Fatal error: Image initialization failed\n");
		return (destroy_image(img, win.mlx), 0);
	}
	return (1);
}
