/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:57:45 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:27:37 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Checks if c is a printable charactere.
 * 	ARGUMENTS:
 * 		int c	: The ascii charactere code.
 * 	RETURN VALUE:
 * 		int	: 1 if c is printable. Else 0.
*/
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
