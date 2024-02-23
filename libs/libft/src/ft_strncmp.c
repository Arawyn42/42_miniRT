/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:54:59 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:39:37 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Compares the first (at most) n bytes of the two strings s1 and s2.
 *	Ft_strncmp returns an integer indicating the result of the comparison
 * 	as follow:
 * 		- 0, if the s1 and s2 are equal;
 * 		- a negative value if s1 is less than s2;
 * 		- a positive value if s1 is greater than s2;
 *	ARGUMENTS:
 *		const char *s1	: The first string.
 *		const char *s2	: The second string.
 *	RETURN VALUE:
 *		int	: The difference (following the ascii code) of the first different
 *		bytes found between s1 and s2.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (i < n && (us1[i] != '\0' || us2[i] != '\0'))
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}
