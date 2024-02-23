/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:34:49 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:27:22 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Checks if c fits into the ASCII character set.
 * 	ARGUMENTS:
 * 		int c	: The ascii charactere code.
 * 	RETURN VALUE:
 * 		int	: 1 if c fits into the ASCII character set. Else 0.
*/
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
