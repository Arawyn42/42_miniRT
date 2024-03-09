/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_shapes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:08:47 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/09 18:43:23 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Sets all datas for a plane.
*/
static void	set_data_plane(t_data *data, char **datas)
{
	t_vector	pos_normal[2];
	double		csr[3];

	pos_normal[0] = str_to_point(datas[1]);
	pos_normal[1] = str_to_point(datas[2]);
	csr[0] = format_color(datas[3]);
	csr[1] = DEFAULT_SPECULAR_POWER;
	if (datas[4])
		csr[1] = ft_atod(datas[4]);
	csr[2] = DEFAULT_REFLECT_RATIO;
	if (datas[4] && datas[5])
		csr[2] = ft_atod(datas[5]);
	set_plane(&(data->planes), pos_normal, csr);
}

/*
 *	Sets all datas for a sphere.
*/
static void	set_data_sphere(t_data *data, char **datas)
{
	t_vector	pos;
	double		rcs[4];

	pos = str_to_point(datas[1]);
	rcs[0] = ft_atod(datas[2]) / 2;
	rcs[1] = format_color(datas[3]);
	rcs[2] = DEFAULT_SPECULAR_POWER;
	if (datas[4])
		rcs[2] = ft_atod(datas[4]);
	rcs[3] = DEFAULT_REFLECT_RATIO;
	if (datas[4] && datas[5])
		rcs[3] = ft_atod(datas[5]);
	set_sphere(&(data->spheres), pos, rcs);
}

/*
 *	Sets all datas for a cylinder.
*/
static void	set_data_cylinder(t_data *data, char **datas)
{
	t_vector	pos_axis[2];
	double		dhcsr[5];

	pos_axis[0] = str_to_point(datas[1]);
	pos_axis[1] = str_to_point(datas[2]);
	dhcsr[0] = ft_atod(datas[3]) / 2;
	dhcsr[1] = ft_atod(datas[4]);
	dhcsr[2] = format_color(datas[5]);
	dhcsr[3] = DEFAULT_SPECULAR_POWER;
	if (datas[6])
		dhcsr[3] = ft_atod(datas[6]);
	dhcsr[4] = DEFAULT_REFLECT_RATIO;
	if (datas[6] && datas[7])
		dhcsr[4] = ft_atod(datas[7]);
	set_cylinder(&(data->cylinders), pos_axis, dhcsr);
}

/*
 *	Sets all datas for a shape.
*/
void	set_data_shapes(t_data *data, char **datas)
{
	if (!ft_strcmp(datas[0], "pl"))
		set_data_plane(data, datas);
	else if (!ft_strcmp(datas[0], "sp"))
		set_data_sphere(data, datas);
	else if (!ft_strcmp(datas[0], "cy"))
		set_data_cylinder(data, datas);
}
