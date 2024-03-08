/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:00:20 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/08 12:44:09 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// int	is_in_shadow(t_data	*data, t_ray dir, t_point point)
// {
// 	t_closest_obj	closest;
// 	t_ray			ray_from_point;

// 	closest = closest_intersection(ray, data->objs);
// 	if (!closest.obj)
// 		return (0);
// 	ray_from_point.origin = intersection_point(ray, closest.distance);
// 	ray_from_point.dir = substract_vect(*data->light->pos, ray_from_point.origin);
// 	closest = closest_intersection(ray_from_point, data->objs);
// 	if (!closest.obj)
// 		return (0);
// 	return (1);
// }
