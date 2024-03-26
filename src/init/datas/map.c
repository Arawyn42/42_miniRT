/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:06:25 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/26 00:11:51 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	destroy_map(t_map *map)
{
	int	i;

	if (map && map->color)
	{
		i = 0;
		while (map->color[i])
		{
			free(map->color[i]);
			i++;
		}
		free(map->color);
		map->color = NULL;
	}
}

static void	fill_map_colors(t_map *map, t_image img)
{
	int				x;
	int				y;
	unsigned int	color;

	x = 0;
	while (x < map->w)
	{
		y = 0;
		while (y < map->h)
		{
			color = *(unsigned int *)(img.addr + y * \
			img.line_length + x * (img.bits_per_pixel / 8));
			map->color[x][y] = int_to_rgb(color);
			y++;
		}
		x++;
	}
}

static void	create_map_colors(t_map *map)
{
	int	i;
	int	j;

	map->color = ft_calloc(map->w + 1, sizeof(t_color *));
	if (!map->color)
		return ;
	i = 0;
	while (i < map->w)
	{
		map->color[i] = ft_calloc(map->h, sizeof(t_color));
		if (!map->color[i])
		{
			j = 0;
			while (j < i)
			{
				free(map->color[j]);
				j++;
			}
			free(map->color);
			return ;
		}
		i++;
	}
	map->color[i] = NULL;
}

static void	fill_map(t_map *map, char *path)
{
	void	*mlx;
	t_image	img;

	mlx = mlx_init();
	if (mlx == NULL)
		return ;
	img.image = mlx_xpm_file_to_image(mlx, path, &map->w, &map->h);
	if (!img.image)
		return ;
	create_map_colors(map);
	img.addr = mlx_get_data_addr(img.image, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	if (map->color)
		fill_map_colors(map, img);
	mlx_destroy_image(mlx, img.image);
	mlx_destroy_display(mlx);
	free(mlx);
}

t_map	create_map(char *path)
{
	t_map	map;

	map.w = 0;
	map.h = 0;
	map.color = NULL;
	if (path)
		fill_map(&map, path);
	return (map);
}
