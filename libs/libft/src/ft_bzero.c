/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:01:15 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:25:49 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Erases the data in the n bytes of the memory starting at the location
 *	pointed to by s, by writting zeros to that area.
 * 	ARGUMENTS:
 * 		void *s		: The starting location.
 * 		size_t n	: The size of the erasing.
 *	RETURN VALUE:
 *		void	: None.
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptrs;
	size_t			i;

	ptrs = (unsigned char *) s;
	i = 0;
	while (i < n)
		ptrs[i++] = 0;
}
