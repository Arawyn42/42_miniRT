/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:41:55 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/18 00:46:13 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	quadratic_return(double x, double y, int sol)
{
	if (!sol)
	{
		if (x > PRECISION)
			return (x);
		else if (y > PRECISION)
			return (y);
	}
	else
	{
		if (y > PRECISION)
			return (y);
		else if (x > PRECISION)
			return (x);
	}
	return (INFINITY);
}

/*
 *	Returns the minimum solution of the quadratic equation, or min if both
 *	values are smaller.
*/
double	quadratic(double a, double b, double c, int	sol)
{
	double	x;
	double	y;
	double	tmp;
	double	delta;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (INFINITY);
	delta = sqrt(delta);
	x = (-b - delta) / (2 * a);
	y = (-b + delta) / (2 * a);
	tmp = x;
	x = fmin(x, y);
	y = fmax(tmp, y);
	return (quadratic_return(x, y, sol));
}
