/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:36:50 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:30:41 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Copies n bytes from memory area src to memory area dest. The memory areas
 *	may overlap.
 *	ARGUMENTS:
 *		void *dest	: The memory of the destination.
 *		void *src	: The memory of the source to copy.
 *		size_t n	: The number of bytes to copy.
 *	RETURN VALUE:
 *		void *	: Pointer to dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;
	size_t			i;

	ptrdest = (unsigned char *) dest;
	ptrsrc = (unsigned char *) src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (ptrsrc < ptrdest && ptrsrc + n >= ptrdest)
	{
		while (i < n)
		{
			ptrdest[n - i - 1] = ptrsrc[n - i - 1];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
