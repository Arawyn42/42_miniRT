/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:55:22 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:34:52 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Combines the string s1 and the string s2 together into one string.
 *	Memory for the new string is obtained with malloc(3), and can be freed
 *	with free(3).
 *	ARGUMENTS:
 *		char const *s1	: The first string, will be at the begginning of
							the final string.
		char const *s2	: The second string, will be at the end of
							the final string.
	RETURN VALUE:
		char *	: The first and the second string joined together.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	res = (char *) malloc(sizeof(char) * lens1 + lens2 + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < lens1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < lens1 + lens2)
	{
		res[i] = s2[i - lens1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
