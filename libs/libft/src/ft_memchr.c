/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:54:55 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:29:55 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Scans the initial n bytes of the memory area pointed to by s for the 
 *	first instance of c.
 * 	ARGUMENTS:
 * 		const void *s	: The pointer toward the memory to search.
 * 		int c			: The character to search in the memory.
 * 		size_t n		: The distance to search in the memory.
 * 	RETURN VALUE:
 * 		void *	: Pointer to the matching byte of NULL if the character does
 * 		not occur in the given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;

	i = 0;
	src = (unsigned char *) s;
	if (n <= 0)
		return (NULL);
	while (src[i] != (unsigned char) c)
	{
		if (i >= n - 1)
			return (NULL);
		i++;
	}
	return (&src[i]);
}
