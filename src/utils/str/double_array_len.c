/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_array_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:30:54 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/02 14:32:11 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns the length of a double array of characters.
*/
int	double_array_len(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
		i++;
	return (i);
}
