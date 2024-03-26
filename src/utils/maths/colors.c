/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:34:53 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/26 17:58:51 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the int color code of a string color code of the form '255,255,255'.
*/
int	format_color(char *colors_str)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	colors = ft_split(colors_str, ',');
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_double_array(colors);
	return ((r << 16) | (g << 8) | b);
}

/*
 *	Converts 3 RGB colors into their int color code.
*/
int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

/*
 *	Converts a int color code into a color structure and returns it.
*/
t_color	int_to_rgb(int color)
{
	int		r;
	int		g;
	int		b;
	t_color	res;

	b = color & 0x0000ff;
	g = (color & 0x00ff00) >> 8;
	r = color >> 16;
	res.r = r;
	res.g = g;
	res.b = b;
	res.sum = r + g + b;
	return (res);
}

/*
 *	Returns the base color of an object.
*/
t_color	get_obj_color(t_obj *obj, t_vector point, t_vector normal)
{
	if (obj->pl && obj->pl->texture.color)
		return (plane_mapping(*obj->pl, obj->pl->texture, point, 30));
	else if (obj->pl)
		return (int_to_rgb(obj->pl->color));
	if (obj->sp && obj->sp->texture.color)
		return (sphere_mapping(*obj->sp, obj->sp->texture, normal));
	else if (obj->sp)
		return (int_to_rgb(obj->sp->color));
	if (obj->cy && obj->cy->texture.color)
		return (cylinder_mapping(*obj->cy, obj->cy->texture, point, normal));
	else if (obj->cy)
		return (int_to_rgb(obj->cy->color));
	if (obj->co && obj->co->texture.color)
		return (cone_mapping(*obj->co, obj->co->texture, point, normal));
	else if (obj->co)
		return (int_to_rgb(obj->co->color));
	if (obj->light)
		return (int_to_rgb(obj->light->color));
	return ((t_color){0, 0, 0, 0});
}

/*
 *	Protects colors in case where it exceeds 255.
*/
void	protect_colors(t_color *color)
{
	if (color->r < 0)
		color->r = 0;
	else if (color->r > 255)
		color->r = 255;
	if (color->g < 0)
		color->g = 0;
	else if (color->g > 255)
		color->g = 255;
	if (color->b < 0)
		color->b = 0;
	else if (color->b > 255)
		color->b = 255;
}
