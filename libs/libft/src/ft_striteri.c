/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:52:17 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:29:37 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Apply the function pointed by f to each characters of the string s.
 *	ARGUMENTS:
 * 		char *s							: The string.
 * 		void (*f)(unsigned int, char*)	: The function.
 *	RETURN VALUE:
 *		void	: None.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
