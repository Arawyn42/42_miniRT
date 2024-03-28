/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:31:00 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/27 19:05:33 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the distance from the ray's origin to the intersection point with
 *	a cone's disk.
*/
static double	cone_disc_intersection(t_ray ray, t_cone co)
{
	double		t;
	double		s;
	double		r;
	t_vector	ray_to_co;

	s = vect_dot(ray.dir, co.axis);
	if (fabs(s) < PRECISION)
		return (INFINITY);
	ray_to_co = substract_vect(co.pos, ray.origin);
	t = vect_dot(co.axis, ray_to_co) / s;
	r = vect_length(substract_vect(intersection_point(ray, t), co.pos));
	if (r <= co.radius)
		return (t);
	return (INFINITY);
}

static double	cone_intersection_result(t_cone co, double s[4], double t[3])
{
	double	sol;

	if (s[2] > 0 || fabs(s[2]) > co.height)
		t[0] = INFINITY;
	if (s[3] > 0 || fabs(s[3]) > co.height)
		t[1] = INFINITY;
	sol = fmin(fmin(t[0], t[1]), t[2]);
	if (sol > PRECISION)
		return (sol);
	return (INFINITY);
}

/*
 *	Returns the distance from the ray's origin to the intersection point
 *	with a cone.
*/
double	cone_intersection(t_ray ray, t_cone co)
{
	t_vector	co_to_ray;
	float		tan2;
	double		s[4];
	double		p[3];
	double		t[3];

	tan2 = co.radius * co.radius / (co.height * co.height);
	co_to_ray = substract_vect(ray.origin, add_vect(co.pos, \
		multiply_vect_scalar(co.axis, co.height)));
	s[0] = vect_dot(ray.dir, co.axis);
	s[1] = vect_dot(co_to_ray, co.axis);
	p[0] = vect_dot(ray.dir, ray.dir) - (tan2 + 1) * s[0] * s[0];
	p[1] = 2 * (vect_dot(ray.dir, co_to_ray) - (tan2 + 1) * s[0] * s[1]);
	p[2] = vect_dot(co_to_ray, co_to_ray) - (tan2 + 1) * s[1] * s[1];
	t[0] = quadratic(p[0], p[1], p[2], 0);
	s[2] = vect_dot(substract_vect(co.pos, \
		intersection_point(ray, t[0])), co.axis);
	t[1] = quadratic(p[0], p[1], p[2], 1);
	s[3] = vect_dot(substract_vect(co.pos, \
		intersection_point(ray, t[1])), co.axis);
	t[2] = cone_disc_intersection(ray, co);
	return (cone_intersection_result(co, s, t));
}
