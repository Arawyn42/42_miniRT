/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:31:36 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/03 22:24:02 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Copies into a new string all the characters of s1 except all the characters
 *	of set found in the beginning and the end of s1.
 * 	Ft_strtrim works as follow :
 *		ft_strtrim("___...,__Hello_world____.__", "_.,") returns "Hello_world".
 *	Memory of the result is obtained with malloc(3), and can be freed with
 *	free(3).
 *	ARGUMENTS:
 *		char const *s1	: The main string to trim.
 *		char const *set	: The set of characters to delete.
 *	RETURN VALUE:
 *		char *	: The result of the trimmed string.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (s1[j] && ft_strchr(set, s1[j]))
		j--;
	res = ft_substr(s1, i, j - i + 1);
	return (res);
}
