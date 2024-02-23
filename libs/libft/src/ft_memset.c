/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:25:25 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:30:56 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Fills the first n bytes of the memory area pointed to by s with
 *	the constant byte c.
 * 	ARGUMENTS:
 * 		void *s		: The memory area to fill.
 * 		int c		: The filling byte.
 * 		size_t n	: The number of bytes to fill.
 *	RETURN VALUE:
 *		void *	: Pointer to the memory area s.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptrs;
	size_t			i;

	ptrs = (unsigned char *) s;
	i = 0;
	while (i < n)
		ptrs[i++] = c;
	return (s);
}
