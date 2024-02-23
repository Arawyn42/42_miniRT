/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2077/07/11 14:15:22 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:30:33 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Copies n bytes from memory area src to memory area dest. The memory areas
 *	must not overlap. Use ft_memmove if the memory areas do overlap.
 *	ARGUMENTS:
 *		void *dest	: The memory of the destination.
 *		void *src	: The memory of the source to copy.
 *		size_t n	: The number of bytes to copy.
 *	RETURN VALUE:
 *		void *	: Pointer to dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrdest;
	unsigned char	*ptrsrc;
	size_t			i;

	ptrdest = (unsigned char *) dest;
	ptrsrc = (unsigned char *) src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		ptrdest[i] = ptrsrc[i];
		i++;
	}
	return (ptrdest);
}
