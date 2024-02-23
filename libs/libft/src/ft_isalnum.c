/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:24:58 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:26:36 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Checks if c is an alphanumeric character.
 *	It is equivalent to (ft_isdigit || ft_isalpha).
 * 	ARGUMENTS:
 * 		int c	: The ascii charactere code.
 * 	RETURN VALUE:
 * 		int	: 1 if c is an alphanumeric character. Else 0.
*/
int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
