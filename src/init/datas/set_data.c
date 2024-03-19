/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:58:35 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/19 04:27:44 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Destroys all datas by freeing all pointers from each data structure.
*/
void	destroy_data(t_data *data)
{
	if (data->objs)
		destroy_objs(&data->objs);
}

/*
 *	Initializes each item in the data structure on NULL.
*/
static void	init_data(t_data *data)
{
	data->a_light.color = rgb_to_int(255, 255, 255);
	data->a_light.ratio = 1;
	data->camera.pos = (t_vector){0, 0, 0};
	data->camera.direction = (t_vector){0, 0, 1};
	data->camera.fov = 150;
	data->objs = NULL;
	data->base[0] = (t_vector){1, 0, 0};
	data->base[1] = (t_vector){0, 1, 0};
	data->base[2] = (t_vector){0, 0, 1};
}

/*
 *	Sets all datas for a light.
*/
static void	set_data_light(t_data *data, char **datas)
{
	t_vector	pos;
	double		ratio;
	int			color;

	pos = str_to_vect(datas[1]);
	ratio = ft_atod(datas[2]);
	color = format_color(datas[3]);
	add_light(data, create_light(pos, ratio, color));
}

/*
 *	Sets all datas from a given line.
*/
static void	set_line_data(char *line, t_data *data)
{
	char	**datas;

	datas = create_data_array(line);
	if (!datas)
		return ;
	if (!datas[0])
		return (free_double_array(datas));
	if (!ft_strcmp(datas[0], "A"))
		data->a_light = set_alight(ft_atod(datas[1]), \
			format_color(datas[2]));
	else if (!ft_strcmp(datas[0], "C"))
		data->camera = set_camera(str_to_vect(datas[1]), \
			str_to_vect(datas[2]), ft_atoi(datas[3]));
	else if (!ft_strcmp(datas[0], "L"))
		set_data_light(data, datas);
	else
		set_data_shapes(data, datas);
	free_double_array(datas);
}

/*
 *	Initializes and sets all datas structures from file.
*/
t_data	set_data(char *file)
{
	char	*line;
	int		fd;
	t_data	data;

	init_data(&data);
	fd = open(file, O_RDONLY, 666);
	line = get_next_line(fd);
	while (line)
	{
		set_line_data(line, &data);
		free(line);
		line = get_next_line(fd);
	}
	data.ray.origin = data.camera.pos;
	data.ray.dir = normalize_vect(data.camera.direction);
	return (close(fd), data);
}
