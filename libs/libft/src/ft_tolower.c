/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:39:24 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:37:21 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	If c is an uppercase letter, ft_tolower returns its lowercase equivalent.
 *	Else return c.
 *	ARGUMENTS:
 *		int c	: A character.
 *	RETURN VALUE:
 *		int	: If c is an uppercase letter, return its lowercase equivalent.
 *		Else returns c.
*/
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
