/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotine <nikotine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:45:25 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/30 12:58:32 by nikotine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*gnl_strjoin(char *s1, char *s2);
int		found_newline(char *buf);
char	*clean_stash(char *stash);
char	*extract_line(char *stash);
char	*read_file(int fd, char *stash);
char	*get_next_line(int fd);

#endif
