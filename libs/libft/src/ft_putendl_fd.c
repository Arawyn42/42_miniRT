/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:19:37 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:31:13 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Writes the string s to the file descriptor fd. Add a newline to the end
 *	ARGUMENTS:
 * 		char *s	: The string to write.
 * 		int fd	: The file descriptor.
 *	RETURN VALUE:
 *		void	: None.
*/
void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
