/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 22:16:01 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:34:05 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Returns a pointer to a new string which is a duplicate of the string.
 *	Memory for the new string is obtained with malloc(3), and can be freed with
 * 	free(3).
 * 	ARGUMENTS:
 * 		const char *s	: The string to copie.
 * 	RETURN VALUE:
 * 		char *	: On success, this function returns a pointer to the duplicated
 * 		string. It returns NULL if insufficient memory was available.
*/
char	*ft_strdup(const char *s)
{
	char	*d;
	int		i;

	d = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
