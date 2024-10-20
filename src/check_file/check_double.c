/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:02:14 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/09 17:15:32 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns 1 if the input string has a double number format, 0 if not.
*/
int	check_double(char *f)
{
	int	dots;
	int	i;

	dots = 0;
	i = 0;
	if (f[0] == '-' || f[0] == '+')
		i++;
	if (f[i] == '.' || f[ft_strlen(f) - 1] == '.')
		return (0);
	while (f[i])
	{
		if ((f[i] < '0' || f[i] > '9') && f[i] != '.')
			return (0);
		if (dots > 1)
			return (0);
		if (f[i] == '.')
			dots++;
		i++;
	}
	return (1);
}
