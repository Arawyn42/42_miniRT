/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:14:49 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:35:28 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Calculates the length of the string pointed to by s, excluding the
 *	terminating null byte '\0'.
 * 	ARGUMENTS:
 * 		const char *s	: The string to calcultate the length from.
 * 	RETURN VALUE:
 * 		size_t	: Number of byte in the string pointed to by s as a size_t.
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
