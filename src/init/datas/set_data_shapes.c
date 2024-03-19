/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_shapes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:08:47 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/19 04:21:08 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Sets all datas for a plane.
*/
static void	set_data_plane(t_data *data, char **datas)
{
	t_vector	pos_normal[2];
	double		cr[2];

	pos_normal[0] = str_to_vect(datas[1]);
	pos_normal[1] = str_to_vect(datas[2]);
	cr[0] = format_color(datas[3]);
	cr[1] = DEFAULT_REFLECT_RATIO;
	if (datas[4])
		cr[1] = ft_atod(datas[4]);
	add_plane(data, create_plane(pos_normal, cr));
}

/*
 *	Sets all datas for a sphere.
*/
static void	set_data_sphere(t_data *data, char **datas)
{
	t_vector	pos;
	double		rcs[4];

	pos = str_to_vect(datas[1]);
	rcs[0] = ft_atod(datas[2]) / 2;
	rcs[1] = format_color(datas[3]);
	rcs[2] = DEFAULT_REFLECT_RATIO;
	if (datas[4])
		rcs[2] = ft_atod(datas[4]);
	add_sphere(data, create_sphere(pos, rcs));
}

/*
 *	Sets all datas for a cylinder.
*/
static void	set_data_cylinder(t_data *data, char **datas)
{
	t_vector	pos_axis[2];
	double		dhcr[5];

	pos_axis[0] = str_to_vect(datas[1]);
	pos_axis[1] = normalize_vect(str_to_vect(datas[2]));
	dhcr[0] = ft_atod(datas[3]) / 2;
	dhcr[1] = ft_atod(datas[4]);
	dhcr[2] = format_color(datas[5]);
	dhcr[3] = DEFAULT_REFLECT_RATIO;
	if (datas[6])
		dhcr[3] = ft_atod(datas[6]);
	add_cylinder(data, create_cylinder(pos_axis, dhcr));
}

/*
 *	Sets all datas for a cone.
*/
static void	set_data_cone(t_data *data, char **datas)
{
	t_vector	pos_axis[2];
	double		rhcr[4];

	pos_axis[0] = str_to_vect(datas[1]);
	pos_axis[1] = normalize_vect(str_to_vect(datas[2]));
	rhcr[0] = ft_atod(datas[3]) / 2;
	rhcr[1] = ft_atod(datas[4]);
	rhcr[2] = format_color(datas[5]);
	rhcr[3] = DEFAULT_REFLECT_RATIO;
	if (datas[6])
		rhcr[3] = ft_atod(datas[6]);
	add_cone(data, create_cone(pos_axis, rhcr));
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
	else if (!ft_strcmp(datas[0], "co"))
		set_data_cone(data, datas);
}
