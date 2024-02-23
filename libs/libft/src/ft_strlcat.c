/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:56:48 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:25:09 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Concatenate the string src at the end of the string dst. The final size of
 *	dst is capped by the size argument (if size is smaller than the original
 *	dst, dst remain unchanged).
 * 	Note that both dst and src must be null-terminated.
 * 	ARGUMENTS:
 * 		char *dst	: The final concatenates string.
 * 		char *src	: The string which will be concatenate at the end of dst.
 * 		size_t size	: The maximum size of dst.
 *	RETURN VALUE:
 *		size_t	: Total length of the string it tried to create. It means
 *		the initial length of dst plus the length of src. While this may seem
 *		somewhat confusing, if was done to make truncation detection simple.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	i;
	size_t	dlen;
	size_t	slen;

	if ((!dst || !src) && !size)
		return (0);
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = dlen;
	j = 0;
	if (size <= dlen)
		return (slen + size);
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dlen + slen);
}
