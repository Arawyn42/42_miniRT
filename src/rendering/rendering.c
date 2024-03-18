/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:46:47 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/18 21:45:03 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Draws the image pixel by pixel after applying raytracing and light effects.
*/
static void	render_no_thread(t_minirt *mem)
{
	t_vector	pixel;
	t_color		color;

	pixel.x = mem->start.x - 1;
	while (++pixel.x <= mem->end.x)
	{
		pixel.y = mem->start.y - 1;
		display_loading("Rendering:", -SCREEN_W / 2, pixel.x, SCREEN_W / 100);
		while (++pixel.y <= mem->end.y)
		{
			mem->data->ray.dir = set_ray(mem->base, pixel.x *  mem->vp.w_ratio, \
				-pixel.y *  mem->vp.h_ratio, VIEWPORT_DIST);
			color = ray_trace(mem->data, mem->data->ray, DEPTH);
			draw_pixels(mem->img, SCREEN_W / 2 + pixel.x, SCREEN_H / 2 \
				+ pixel.y, rgb_to_int(color.r, color.g, color.b));
		}
	}
}

static void	*render_threads(void *args)
{
	t_minirt	*mem;
	t_vector	pixel;
	t_color		color;

	mem = (t_minirt *)args;
	pixel.x = mem->start.x - 1;
	while (++pixel.x <= mem->end.x)
	{
		pixel.y = mem->start.y - 1;
		if (mem->start.y < -SCREEN_H / 2 + 1)
			display_loading("Rendering:", -SCREEN_W / 2, \
				pixel.x, SCREEN_W / 100);
		while (++pixel.y <= mem->end.y)
		{
			mem->data->ray.dir = set_ray(mem->base, pixel.x * mem->vp.w_ratio,
				-pixel.y *  mem->vp.h_ratio, VIEWPORT_DIST);
			color = ray_trace(mem->data, mem->data->ray, DEPTH);
			draw_pixels(mem->img, SCREEN_W / 2 + pixel.x, SCREEN_H / 2 
				+ pixel.y, rgb_to_int(color.r, color.g, color.b));
		}
	}
	return (NULL);
}

static t_minirt	set_datas_thread(t_minirt *mem, int i, int threads)
{
	t_minirt	data;

	data = *mem;
	data.start.y = (int)(-SCREEN_H / 2 + i * SCREEN_H / threads);
	data.end.y = (int)(-SCREEN_H / 2 + (i + 1) * SCREEN_H / threads - 1);
	if (i == threads - 1)
		data.end.y = SCREEN_H / 2;
	return (data);
}

static void	launch_threads(t_minirt *mem, int threads, char *file)
{
	pthread_t	*th;
	t_minirt	*data;
	int			i;

	(void) file;
	th = ft_calloc(threads, sizeof(pthread_t));
	data = ft_calloc(threads, sizeof(t_minirt));
	i = -1;
	while (++i < threads)
		data[i] = set_datas_thread(mem, i, threads);
	while (--i >= 0)
		if (pthread_create(&th[i], NULL, &render_threads, &data[i]))
			return (free(th), free(data), perror(""));
	while (++i < threads)
		pthread_join(th[i], NULL);
	free(th);
	free(data);
}

/*
 *	Calls the main rendering function and prints the resulting image.
*/
void	rendering(t_minirt *mem, int threads, char *file)
{
	ft_bzero(mem->img->addr, SCREEN_H * SCREEN_W);
	mlx_hook(mem->win->window, 17, 0L, &exit_handling, mem);
	mlx_hook(mem->win->window, 2, 1L << 0, &user_input, mem);
	rotate_base(mem->base, mem->data->camera->direction);
	if (!threads)
		render_no_thread(mem);
	else
		launch_threads(mem, threads, file);
	mlx_put_image_to_window(mem->win->mlx, \
		mem->win->window, mem->img->image, 0, 0);
	mlx_loop(mem->win->mlx);
}
