/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:34:37 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/25 15:14:37 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Creates and sets a plane's base.
*/
static void	create_plane_base(t_plane *plane)
{
	t_ray	ray;
	double	distance;

	ray.origin = add_vect((t_vector){plane->normal.y, plane->normal.z, \
		plane->normal.x}, plane->pos);
	ray.dir = plane->normal;
	distance = pl_intersection(ray, *plane);
	plane->base[2] = normalize_vect(substract_vect(intersection_point(ray, \
		distance), plane->pos));
	plane->base[1] = plane->normal;
	plane->base[0] = normalize_vect(vect_cross_product(plane->base[1], \
		plane->base[2]));
}

/*
 *	Creates, sets the values and returns a plane structure.
*/
t_plane	*create_plane(t_vector pos_normal[2], double cr[2])
{
	t_plane	*plane;

	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
	{
		print_error("Error: Plane: Calloc error.\n");
		return (NULL);
	}
	plane->pos = pos_normal[0];
	plane->normal = pos_normal[1];
	plane->color = cr[0];
	plane->reflect = cr[1];
	create_plane_base(plane);
	return (plane);
}

/*
*	Adds a plane into the objects list.
*/
void	add_plane(t_data *data, t_plane *plane)
{
	t_obj		*new_obj;
	t_obj		*last_obj;

	new_obj = create_new_obj();
	new_obj->pl = plane;
	if (!data->objs)
		data->objs = new_obj;
	else
	{
		last_obj = get_last_obj(data->objs);
		last_obj->next = new_obj;
	}
}
