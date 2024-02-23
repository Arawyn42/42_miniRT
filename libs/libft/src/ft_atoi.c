/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:42:54 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:25:37 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Convert the initial portion of the string pointed to by nptr to int.
 *	Return the converted value as an integer or 0 on error.
 *	No overflow or underflow are done. Only base-10 input cat be converted.
 *	ARGUMENTS:
 *		const char *nptr	: The string to be converted.
 *	RETURN VALUE:
 *		int	: converted value or 0 on error.
*/
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] && (nptr[i] >= 9 && nptr[i] <= 13)) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
