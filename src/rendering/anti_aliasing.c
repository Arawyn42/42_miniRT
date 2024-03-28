/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:32:12 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/27 19:01:33 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the average color 
*/
static t_color	get_average_color(t_image img, int x, int y)
{
	t_color	color[8];
	t_color	avg;

	color[0] = get_pixel_color(img, x - 1, y + 1);
	color[1] = get_pixel_color(img, x + 1, y);
	color[2] = get_pixel_color(img, x + 1, y + 1);
	color[3] = get_pixel_color(img, x, y + 1);
	color[4] = get_pixel_color(img, x - 1, y);
	color[5] = get_pixel_color(img, x - 1, y - 1);
	color[6] = get_pixel_color(img, x, y - 1);
	color[7] = get_pixel_color(img, x + 1, y - 1);
	avg.r = (2 * (color[0].r + color[1].r + color[2].r + color[3].r) / 4 \
		+ (color[4].r + color[5].r + color[6].r + color[7].r) / 4) / 3;
	avg.g = (2 * (color[0].g + color[1].g + color[2].g + color[3].g) / 4 \
		+ (color[4].g + color[5].g + color[6].g + color[7].g) / 4) / 3;
	avg.b = (2 * (color[0].b + color[1].b + color[2].b + color[3].b) / 4 \
		+ (color[4].b + color[5].b + color[6].b + color[7].b) / 4) / 3;
	protect_colors(&avg);
	avg.sum = avg.r + avg.g + avg.b;
	return (avg);
}

/*
 *	Very basic anti_aliasing.
*/
void	anti_aliasing(t_minirt *mem, double ratio)
{
	int		x;
	int		y;
	t_color	clr;
	t_color	avg;

	x = mem->start.x + 1;
	while (x < mem->end.x)
	{
		y = mem->start.y + 1;
		display_loading("Anti-aliasing:", -SCREEN_W / 2, x, SCREEN_W / 100);
		while (y < mem->end.y)
		{
			clr = get_pixel_color(mem->img, \
				SCREEN_W / 2 + x, SCREEN_H / 2 + y);
			avg = get_average_color(mem->img, \
				SCREEN_W / 2 + x, SCREEN_H / 2 + y);
			if (clr.sum < avg.sum - 100 || clr.sum > avg.sum + 100)
				clr = reflection_color(clr, avg, ratio, 1);
			draw_pixels(&mem->img, SCREEN_W / 2 + x, \
				SCREEN_H / 2 + y, rgb_to_int(clr.r, clr.g, clr.b));
			y++;
		}
		x++;
	}
}
