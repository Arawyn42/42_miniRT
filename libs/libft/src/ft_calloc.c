/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:58:44 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:26:22 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Allocates memory for an array of nmemb elements of size  bytes each, 
 *	and returns a pointer to the allocated memory. The memory is set to zero.
 *	If nmemb or size is 0, the returns is a unique pointer value that can later
 * 	be successfully passed to free(). 
 * 	If the multiplication of nmemb and size would result in integer overflow, 
 * 	then returns NULL.
 * 	ARGUMENTS:
 * 		size_t nmemb	: The number of element.
 * 		size_t size		: The size of each elements.
 * 	RETURN VALUE:
 * 		void *	: Pointer to the allocated memory.
 * 		If the multiplication of nmemb and size would result in integer 
 * 		overflow, then returns NULL.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		overflow_test;

	overflow_test = nmemb * size;
	if (!overflow_test)
		return (malloc(0));
	if (overflow_test / nmemb != size)
		return (NULL);
	ptr = (void *) malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
