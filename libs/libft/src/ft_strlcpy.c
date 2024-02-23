/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:10:33 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:35:08 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Copies src into dst. The final size of dst is capped by the size argument 
 * 	Note that src must be null-terminated.
 *	ARGUMENTS:
 * 		char *dst	: The destination of the copie.
 * 		char *dst	: The source to be copied.
 * 		size_t size	: The maximum size of dst.
 * 	RETURN VALUE:
 * 		size_t	: Final length of dst.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
