/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:54:10 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/25 15:16:16 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Creates and sets a cylinder's base.
*/
static void	create_cylinder_base(t_cylinder *cylinder)
{
	t_ray	ray;
	double	distance;
	t_plane	plane;

	ray.origin = add_vect((t_vector){cylinder->axis.y, cylinder->axis.z, \
		cylinder->axis.x}, cylinder->pos);
	ray.dir = cylinder->axis;
	plane.pos = cylinder->pos;
	plane.normal = cylinder->axis;
	distance = pl_intersection(ray, plane);
	cylinder->base[2] = normalize_vect(substract_vect(intersection_point(ray, \
		distance), cylinder->pos));
	cylinder->base[1] = cylinder->axis;
	cylinder->base[0] = normalize_vect(vect_cross_product(cylinder->base[1], \
		cylinder->base[2]));
}

/*
 *	Creates, sets the values and returns a cylinder structure.
*/
t_cylinder	*create_cylinder(t_vector pos_axis[2], double dhcr[4])
{
	t_cylinder	*cylinder;

	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
	{
		print_error("Error: Cylinder: Calloc error.\n");
		return (NULL);
	}
	cylinder->pos = pos_axis[0];
	cylinder->axis = pos_axis[1];
	cylinder->radius = dhcr[0];
	cylinder->height = dhcr[1];
	cylinder->color = (int)dhcr[2];
	cylinder->reflect = dhcr[3];
	create_cylinder_base(cylinder);
	return (cylinder);
}

/*
*	Adds a cylinder into the objects list.
*/
void	add_cylinder(t_data *data, t_cylinder *cylinder)
{
	t_obj		*new_obj;
	t_obj		*last_obj;

	new_obj = create_new_obj();
	new_obj->cy = cylinder;
	if (!data->objs)
		data->objs = new_obj;
	else
	{
		last_obj = get_last_obj(data->objs);
		last_obj->next = new_obj;
	}
}
