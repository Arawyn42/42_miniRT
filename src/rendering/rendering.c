/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:46:47 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/08 12:39:48 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Draws the image pixel by pixel after applying raytracing and light effects.
*/
static void	render(t_data *data, t_image *img, t_point base[3])
{
	t_ray		ray;
	t_point		pixel;
	t_color		color;
	t_viewport	vp;

	color = (t_color){0, 0, 0, 0};
	init_objs(data);
	init_ray(data, &ray);
	vp = init_viewport(data->camera->fov, VIEWPORT_DIST);
	pixel.x = -SCREEN_W / 2 - 1;
	while (++pixel.x <= SCREEN_W / 2)
	{
		pixel.y = -SCREEN_H / 2 - 1;
		display_loading("Rendering:", -SCREEN_W / 2, pixel.x, SCREEN_W / 100);
		while (++pixel.y <= SCREEN_H / 2)
		{
			ray.dir = set_ray(base, pixel.x * vp.w_ratio, \
				-pixel.y * vp.h_ratio, VIEWPORT_DIST);
			color = ray_trace(data, ray, DEPTH);
			draw_pixels(img, SCREEN_W / 2 + pixel.x, SCREEN_H / 2 \
				+ pixel.y, rgb_to_int(color.r, color.g, color.b));
		}
	}
}

/*
 *	Calls the main rendering function and prints the resulting image.
*/
void	rendering(t_minirt *mem)
{
	t_point		base[3];

	base[0] = (t_point){1, 0, 0};
	base[1] = (t_point){0, 1, 0};
	base[2] = (t_point){0, 0, 1};
	rotate_base(base, *mem->data->camera->direction);
	ft_bzero(mem->img->addr, 4 * SCREEN_H * SCREEN_W);
	render(mem->data, mem->img, base);
	mlx_put_image_to_window(mem->win->mlx, mem->win->window,
		mem->img->image, 0, 0);
}
