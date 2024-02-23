/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:15:31 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:32:54 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Writes the string s to the file descriptor fd.
 *	ARGUMENTS:
 * 		char *s	: The string to write.
 * 		int fd	: The file descriptor.
 *	RETURN VALUE:
 *		void	: None.
*/
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
