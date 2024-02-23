/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:40:22 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:36:52 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Locates the first occurrence of the null-terminated string little in the 
 *	string big, where not more than len characters are searched.
 * 	Characters that appear after a '\0' character are not searched.
 *	ARGUMENTS:
 *		const char *big		: The main string.
 *		const char *little	: The smaller string to search in the main string.
 *		size_t len			: The number of characters max to search.
 *	RETURN VALUE:
 *		char *	: Pointer to the first character of the first occurrence of 
 *		little inside of big. NULL if not found.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!big || !little) && !len)
		return (NULL);
	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *) &big[i]);
		}
		i++;
	}
	return (0);
}
