/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:43:13 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:37:04 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Search the byte c in the string s and returns a pointer to the last
 *	occurrence found.
 *	ARGUMENTS:
 * 		const char *s	: The string.
 * 		int c			: The byte to search.
 * 	RETURN VALUE:
 * 		char *	: Pointer to the matched character or NULL if the character 
 * 		is not found. 
 * 		Note that the terminating null byte is considered part of the string, 
 * 		so that if c is specified as '\0', this function return a pointer to 
 * 		the terminator.
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*src;
	size_t	i;

	src = (char *) s;
	i = ft_strlen(src);
	while (src[i] != (unsigned char) c)
	{
		if (i <= 0)
			return (NULL);
		i--;
	}
	return (&src[i]);
}
