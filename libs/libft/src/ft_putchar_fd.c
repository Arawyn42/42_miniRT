/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:08:24 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:31:06 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Writes the char c to the file descriptor fd.
 *	ARGUMENTS:
 * 		char c	: The char to write.
 * 		int fd	: The file descriptor.
 *	RETURN VALUE:
 *		void	: None.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
