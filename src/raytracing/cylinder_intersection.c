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

static int	check_height(t_ray ray, t_cylinder cy, double distance)
{
	t_vector	center_to_point;
	double		height;

	center_to_point = substract_vect(add_vect(ray.origin, \
		multiply_vect_scalar(ray.dir, distance)), cy.pos);
	height = vect_dot(center_to_point, cy.axis);
	if (height < 0 || height > cy.height)
		return (0);
	return (1);
}

static double	height_intersection(t_ray ray, \
	t_cylinder cy, t_vector ray_to_cy)
{
	double		distance;
	t_vector	v1;
	t_vector	v2;
	double		s;

	s = vect_dot(ray.dir, cy.axis);
	v1 = substract_vect(ray.dir, multiply_vect_scalar(cy.axis, s));
	s = vect_dot(ray_to_cy, cy.axis);
	v2 = substract_vect(ray_to_cy, multiply_vect_scalar(cy.axis, s));
	distance = quadratic(vect_dot(v1, v1), 2 * vect_dot(v1, v2), \
		vect_dot(v2, v2) - cy.radius * cy.radius, 0);
	if (!check_height(ray, cy, distance))
		return (INFINITY);
	return (distance);
}

static int	check_radius(t_ray ray, t_cylinder cy, double distance, int inter)
{
	t_vector	center_to_point;
	t_vector	center;
	double		radius;

	center = cy.pos;
	if (inter == 2)
		center = add_vect(cy.pos, multiply_vect_scalar(cy.axis, cy.height));
	center_to_point = substract_vect(add_vect(ray.origin, \
		multiply_vect_scalar(ray.dir, distance)), center);
	radius = vect_length(center_to_point);
	if (radius >= cy.radius)
		return (0);
	return (1);
}

static double	disc_intersection(t_ray ray, t_cylinder cy)
{
	t_plane	plane;
	double	inter1;
	double	inter2;
	double	ray_dot_axis;

	ray_dot_axis = vect_dot(ray.dir, cy.axis);
	if (fabs(ray_dot_axis) < PRECISION)
		return (INFINITY);
	plane.pos = cy.pos;
	plane.normal = substract_vect((t_vector){0, 0, 0}, cy.axis);
	inter1 = pl_intersection(ray, plane);
	if (!check_radius(ray, cy, inter1, 1))
		inter1 = INFINITY;
	plane.pos = add_vect(cy.pos, multiply_vect_scalar(cy.axis, cy.height));
	plane.normal = cy.axis;
	inter2 = pl_intersection(ray, plane);
	if (!check_radius(ray, cy, inter2, 2))
		inter2 = INFINITY;
	if (inter1 < inter2 && inter1 > PRECISION)
		return (inter1);
	else if (inter2 > PRECISION)
		return (inter2);
	return (INFINITY);
}

double	cy_intersection(t_ray ray, t_cylinder cylinder)
{
	double		inter1;
	double		inter2;
	t_vector	ray_to_cy;

	ray_to_cy = substract_vect(ray.origin, cylinder.pos);
	inter1 = disc_intersection(ray, cylinder);
	inter2 = height_intersection(ray, cylinder, ray_to_cy);
	if (inter1 <= inter2 && inter1 > PRECISION)
		return (inter1);
	else if (inter2 > PRECISION)
		return (inter2);
	return (INFINITY);
}
