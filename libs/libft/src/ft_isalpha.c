/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:21:46 by nikotine          #+#    #+#             */
/*   Updated: 2023/12/04 10:27:16 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Checks if c is an alphabetic character.
 * 	ARGUMENTS:
 * 		int c	: The ascii charactere code.
 * 	RETURN VALUE:
 * 		int	: 1 if c is an alphabetic character. Else 0.
*/
int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
