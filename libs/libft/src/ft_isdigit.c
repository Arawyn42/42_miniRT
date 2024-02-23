/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:06:22 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:27:28 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	Checks if c is a digit.
 * 	ARGUMENTS:
 * 		int c	: The ascii charactere code.
 * 	RETURN VALUE:
 * 		int	: 1 if c is a digit. Else 0.
*/
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
