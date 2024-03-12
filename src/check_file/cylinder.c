/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arawyn <arawyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:13:12 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/11 17:35:02 by arawyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Second part of the check_cylinder function.
*/
static int	check_cylinder2(char **data)
{
	
	if (data[6] && (!check_double(data[6]) \
		|| ft_atod(data[6]) < 0.0 || ft_atod(data[6]) > 1.0))
	{
		print_error("Error: Cylinder: Reflect ratio must be in range ");
		print_error("[0.0,1.0]. Example: 0.6\n");
		return (0);
	}
	return (1);
}

/*
 *	Returns 1 if the given line has the correct format for cylinder descriptor,
 *	0 if not.
*/
int	check_cylinder(char **data)
{
	int	len;

	len = double_array_len(data);
	if (len < 6 || len > 7)
		return (print_error("Error: Cylinder needs 5 or 6 arguments.\n"));
	if (!check_coordinates(data[1]))
		return (print_error("Error: Cylinder: Wrong coordinates.\n"));
	if (!check_orientation_vector(data[2]))
		return (print_error("Error: Cylinder: Wrong orientation vector. It "),
			print_error("must be in range [-1.0,1.0] for each axis.\n"));
	if (!check_double(data[3]) || ft_atod(data[3]) < 0.0)
		return (print_error("Error: Cylinder: Invalid diameter.\n"));
	if (!check_double(data[4]) || ft_atod(data[4]) < 0.0)
		return (print_error("Error: Cylinder: Invalid height.\n"));
	if (!check_rgb(data[5]))
	{
		print_error("Error: Cylinder: RGB colors ");
		print_error("must be in range [0-255]. Example: 255,255,255\n");
		return (0);
	}
	if (!check_cylinder2(data))
		return (0);
	return (1);
}
