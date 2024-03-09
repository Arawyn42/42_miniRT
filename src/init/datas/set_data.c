/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:58:35 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/09 18:11:47 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Destroys all datas by freeing all pointers from each data structure.
*/
void	destroy_data(t_data *data)
{
	if (data->a_light)
		destroy_alight(data->a_light);
	if (data->camera)
		destroy_camera(data->camera);
	if (data->light)
		destroy_light(data->light);
	if (data->planes)
		destroy_plane(&data->planes);
	if (data->spheres)
		destroy_sphere(&data->spheres);
	if (data->cylinders)
		destroy_cylinder(&data->cylinders);
	if (data->objs)
		destroy_objs(&data->objs);
	free(data);
}

/*
 *	Initializes each item in the data structure on NULL.
*/
static void	set_data_null(t_data *data)
{
	data->a_light = NULL;
	data->camera = NULL;
	data->light = NULL;
	data->planes = NULL;
	data->spheres = NULL;
	data->cylinders = NULL;
	data->objs = NULL;
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
		data->camera = set_camera(str_to_point(datas[1]), \
			str_to_point(datas[2]), ft_atoi(datas[3]));
	else if (!ft_strcmp(datas[0], "L"))
		data->light = set_light(str_to_point(datas[1]), \
			ft_atod(datas[2]), format_color(datas[3]));
	else
		set_data_shapes(data, datas);
	free_double_array(datas);
}

/*
 *	Initializes and sets all datas structures from file.
*/
t_data	*set_data(char *file)
{
	char	*line;
	int		fd;
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	set_data_null(data);
	fd = open(file, O_RDONLY, 666);
	line = get_next_line(fd);
	while (line)
	{
		set_line_data(line, data);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), data);
}
