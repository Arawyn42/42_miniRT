/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:10:14 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/04 16:30:35 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_height(t_ray ray, t_cylinder *cy, double distance)
{
	t_vector	center_to_point;
	double		height;

	center_to_point = substract_vect(add_vect(ray.origin, \
		multiply_vect_scalar(ray.dir, distance)), cy->pos);
	height = 2 * fabs(vect_dot(center_to_point, cy->axis));
	if (height > cy->height)
		return (0);
	return (1);
}

static double	height_intersection(t_ray ray, \
	t_cylinder *cy, t_vector ray_to_cy)
{
	double		distance;
	t_vector	v1;
	t_vector	v2;
	double		s1;
	double		s2;

	s1 = vect_dot(ray_to_cy, cy->axis);
	s2 = vect_dot(cy->axis, cy->axis);
	v1 = substract_vect(ray_to_cy, multiply_vect_scalar(cy->axis, s1 / s2));
	s1 = vect_dot(ray.dir, cy->axis);
	v2 = substract_vect(ray.dir, multiply_vect_scalar(cy->axis, s1 / s2));
	distance = quadratic_min(vect_dot(v2, v2), 2 * vect_dot(v1, v2), \
		vect_dot(v1, v1) - pow(cy->radius, 2), PRECISION);
	if (!check_height(ray, cy, distance))
		return (INFINITY);
	return (distance);
}

static int	check_radius(t_ray ray, t_cylinder *cy, double distance)
{
	t_vector	center_to_point;
	t_vector	radius;
	double		scalar;

	center_to_point = substract_vect(add_vect(ray.origin, \
		multiply_vect_scalar(ray.dir, distance)), cy->pos);
	scalar = vect_dot(center_to_point, cy->axis) \
		/ vect_dot(cy->axis, cy->axis);
	radius = substract_vect(center_to_point, multiply_vect_scalar(cy->axis, scalar));
	if (vect_length(radius) > cy->radius)
		return (0);
	return (1);
}

static double	disc_intersection(t_ray ray, t_cylinder *cy, t_vector ray_to_cy)
{
	double	inter1;
	double	inter2;
	double	ray_dot_axis;

	ray_dot_axis = vect_dot(ray.dir, cy->axis);
	if (fabs(ray_dot_axis) < PRECISION)
		return (INFINITY);
	inter1 = (cy->height - 2 * vect_dot(ray_to_cy, \
		cy->axis)) / (2 * ray_dot_axis);
	if (!check_radius(ray, cy, inter1))
		inter1 = INFINITY;
	inter2 = (-cy->height - 2 * vect_dot(ray_to_cy, \
		cy->axis)) / (2 * ray_dot_axis);
	if (!check_radius(ray, cy, inter2))
		inter2 = INFINITY;
	if (inter1 < inter2 && inter1 > PRECISION)
		return (inter1);
	else if (inter2 > PRECISION)
		return (inter2);
	return (INFINITY);
}

double	cy_intersection(t_ray ray, t_cylinder *cylinder)
{
	double		inter1;
	double		inter2;
	t_vector	ray_to_cy;

	ray_to_cy = substract_vect(ray.origin, cylinder->pos);
	inter1 = disc_intersection(ray, cylinder, ray_to_cy);
	inter2 = height_intersection(ray, cylinder, ray_to_cy);
	if (inter1 < inter2 && inter1 > PRECISION)
		return (inter1);
	else if (inter2 > PRECISION)
		return (inter2);
	return (INFINITY);
}

// double	cy_intersection(t_ray ray, t_cylinder *cylinder)
// {
// 	double	a;
// 	double	b;
// 	double	c;
// 	t_vector	r_to_c;

// 	r_to_c = substract_vect(*cylinder->pos, ray.origin);
// 	a = vect_dot(ray.dir, ray.dir) - pow(vect_dot(ray.dir, *cylinder->axis), 2);
// 	b = 2 * (vect_dot(ray.dir, r_to_c) - vect_dot(ray.dir,
//	*cylinder->axis) * vect_dot(r_to_c, *cylinder->axis));
// 	c = vect_dot(r_to_c, r_to_c) - pow(vect_dot(r_to_c, 
//	*cylinder->axis), 2) - cylinder->radius * cylinder->radius;
// 	printf("res cy = %f\n", quadratic_min(a, b, c, PRECISION));
// 	return (quadratic_min(a, b, c, PRECISION));
// }
