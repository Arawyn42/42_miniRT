/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:24:56 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:20:31 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Returns a substring of the string pointed by s starting at the start
 *	location and of the max size of len.
 *	Memory for the new string is obtained with malloc(3), and can be freed with
 *	free(3).
 *	ARGUMENTS:
 *		char const *s		: The main string.
 *		unsigned int start	: The starting position of the substring.
 *		size_t len			: The maximum size of the substring.
 *	RETURN VALUE:
 *		char *	: The substring of the string pointed by s.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size_res;
	size_t	i;

	size_res = ft_strlen(s) - start;
	if (size_res > len)
		size_res = len;
	if (start >= ft_strlen(s))
	{
		res = (char *) malloc(sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	res = (char *) malloc(sizeof(char) * size_res + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < size_res)
		res[i] = s[start + i];
	res[i] = '\0';
	return (res);
}
