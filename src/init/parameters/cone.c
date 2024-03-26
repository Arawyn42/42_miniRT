/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:07:56 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/17 16:52:15 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Creates and sets a cone's base.
*/
static void	create_cone_base(t_cone *cone)
{
	t_ray	ray;
	double	distance;
	t_plane	plane;

	ray.origin = add_vect((t_vector){cone->axis.y, cone->axis.z, \
		cone->axis.x}, cone->pos);
	ray.dir = cone->axis;
	plane.pos = cone->pos;
	plane.normal = cone->axis;
	distance = pl_intersection(ray, plane);
	cone->base[1] = cone->axis;
	cone->base[2] = normalize_vect(substract_vect(intersection_point(ray, \
		distance), cone->pos));
	cone->base[0] = normalize_vect(vect_cross_product(cone->base[1], \
		cone->base[2]));
}

/*
 *	Creates, sets the values and return a cone structure.
*/
t_cone	*create_cone(t_vector pos_axis[2], double rhcr[4], char *map[2])
{
	t_cone	*cone;

	cone = ft_calloc(1, sizeof(t_cone));
	if (!cone)
	{
		print_error("Error: Cone: Calloc error.\n");
		return (NULL);
	}
	cone->pos = pos_axis[0];
	cone->axis = pos_axis[1];
	cone->radius = rhcr[0];
	cone->height = rhcr[1];
	cone->color = rhcr[2];
	cone->reflect = rhcr[3];
	create_cone_base(cone);
	cone->normal_map = create_map(map[0]);
	cone->texture = create_map(map[1]);
	return (cone);
}

/*
*	Adds a cone into the objects list.
*/
void	add_cone(t_data *data, t_cone *cone)
{
	t_obj		*new_obj;
	t_obj		*last_obj;

	new_obj = create_new_obj();
	new_obj->co = cone;
	if (!data->objs)
		data->objs = new_obj;
	else
	{
		last_obj = get_last_obj(data->objs);
		last_obj->next = new_obj;
	}
}
