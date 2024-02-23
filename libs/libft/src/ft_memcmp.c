/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:12:22 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:30:14 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Compares the first n bytes of the memory areas s1 and s2.
 *	ARGUMENTS:
 * 		const void *s1	: The first memory area.
 * 		const void *s2	: The second memory area.
 *	RETURN VALUE:
 *		int	: Integer less than, equal to, or greater than zero if the
 *		first n bytes of s1 is found, respectively, to be less than, to
 *		match, or be greater than the first n bytes of s2.
 *		For a nonzero return value, the sign is determined by the sign of 
 *		the difference between the first pair of bytes that differ in s1 and s2.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;
	size_t			i;

	ptrs1 = (unsigned char *) s1;
	ptrs2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (ptrs1[i] != ptrs2[i])
			return (ptrs1[i] - ptrs2[i]);
		i++;
	}
	return (0);
}
