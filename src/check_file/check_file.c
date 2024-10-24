/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arawyn <arawyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:40:45 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/21 00:54:34 by arawyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns 1 if the file extension is correct (.rt), 0 if not.
*/
static int	check_extension(char *file)
{
	int		len;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror(file), 0);
	close(fd);
	len = ft_strlen(file);
	if (file[len - 1] != 't' || file[len - 2] != 'r' || file[len - 3] != '.')
	{
		print_error("Error: The scene description file must ");
		print_error("have the \".rt\" extension.\n");
		return (0);
	}
	return (1);
}

/*
 *	Returns 1 if the given line has a correct format, 0 if not.
*/
static int	check_line(char *line)
{
	char	**data;

	if (is_empty(line))
		return (1);
	data = create_data_array(line);
	if (!data)
		return (1);
	if (!ft_strcmp(data[0], "A") && !check_ambiant_lightning(data))
		return (free_double_array(data), 0);
	if (!ft_strcmp(data[0], "C") && !check_camera(data))
		return (free_double_array(data), 0);
	if (!ft_strcmp(data[0], "L") && !check_light(data))
		return (free_double_array(data), 0);
	if (!ft_strcmp(data[0], "pl") && !check_plane(data))
		return (free_double_array(data), 0);
	if (!ft_strcmp(data[0], "sp") && !check_sphere(data))
		return (free_double_array(data), 0);
	if (!ft_strcmp(data[0], "cy") && !check_cylinder(data))
		return (free_double_array(data), 0);
	if (!ft_strcmp(data[0], "co") && !check_cone(data))
		return (free_double_array(data), 0);
	return (free_double_array(data), 1);
}

/*
 *	Returns 1 if the given file has a correct format, 0 if not.
*/
int	check_file(char *file)
{
	char	*line;
	int		fd;

	if (!check_extension(file))
		return (0);
	fd = open(file, O_RDONLY, 666);
	line = get_next_line(fd);
	while (line)
	{
		if ((!is_empty(line) && !check_identifier(line)) || !check_line(line))
			return (close(fd), free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 1);
}
