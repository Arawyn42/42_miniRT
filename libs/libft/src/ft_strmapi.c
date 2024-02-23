/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:18:32 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:35:40 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Apply the function pointed by f to each characters of the string 
 *	pointed by s. The result of the function f is stored in a new string.
 *	Memory for the new string is obtained with malloc(3), and can be freed with
 *	free(3).
 *	ARGUMENTS:
 *		char consts *s					: The string.
 *		char (*f)(unsigned int, char)	: The function.
 *	RETURN VALUE:
 *		char *	: The new string that has been passed to the function pointed
 *		by f.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (!s || !f)
		return (NULL);
	res = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
