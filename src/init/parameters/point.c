/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:31:47 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/09 15:01:57 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	str_to_point(char *str)
{
	char	**split;
	t_point	point;

	split = ft_split(str, ',');
	point.x = ft_atod(split[0]);
	point.y = ft_atod(split[1]);
	point.z = ft_atod(split[2]);
	free_double_array(split);
	return (point);
}
 