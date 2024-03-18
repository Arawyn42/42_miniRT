/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:31:47 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/17 15:01:53 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	str_to_vect(char *str)
{
	char		**split;
	t_vector	point;

	split = ft_split(str, ',');
	point.x = ft_atod(split[0]);
	point.y = ft_atod(split[1]);
	point.z = ft_atod(split[2]);
	free_double_array(split);
	return (point);
}
