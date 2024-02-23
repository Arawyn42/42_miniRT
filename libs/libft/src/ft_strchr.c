/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:02:39 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:33:39 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Search the byte c in the string s and returns a pointer to the first
 *	occurrence found.
 *	ARGUMENTS:
 * 		const char *s	: The string.
 * 		int c			: The byte to search.
 * 	RETURN VALUE:
 * 		char *	: Pointer to the matched character of NULL if the character 
 * 		is not found. 
 * 		Note that the terminating null byte is considered part or the string, 
 * 		so that if c is specified as '\0', this function return a pointer to 
 * 		the terminator.
*/
char	*ft_strchr(const char *s, int c)
{
	char	*src;

	src = (char *) s;
	while (*src != (unsigned char) c)
	{
		if (*src == '\0')
			return (NULL);
		src++;
	}
	return (src);
}
