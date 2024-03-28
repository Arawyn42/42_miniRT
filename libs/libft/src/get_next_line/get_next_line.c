/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:48:58 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/28 16:40:27 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 *	Search in buf for a '\n' and returns the position of the first one
 * 	encountered. Returns -1 if no '\n' are found.
*/
int	found_newline(char *buf)
{
	int	i;

	i = -1;
	if (!buf)
		return (-1);
	while (buf[++i])
	{
		if (buf[i] == '\n')
			return (i);
	}
	return (-1);
}

/*
 *	Seach in the stash for a '\n' and cleans everything before it then 
 *	returns the cleaned stash.
 *	Returns NULL if no '\n' are found.
*/
char	*clean_stash(char *stash)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!res)
		return (NULL);
	j = 0;
	i++;
	while (stash[i])
		res[j++] = stash[i++];
	res[j] = '\0';
	free(stash);
	return (res);
}

/*
 *	Read the stash and substract only one line to it and returns it.
 *	Returns NULL if stash is empty.
*/
char	*extract_line(char *stash)
{
	char	*line;
	int		line_size;
	int		i;

	line_size = 0;
	while (stash[line_size] != '\n' && stash[line_size] != '\0')
		line_size++;
	if (stash[line_size] == '\0')
	{
		if (line_size == 0)
			return (NULL);
		return (ft_strdup(stash));
	}
	i = 0;
	line_size++;
	line = (char *)malloc(sizeof(char) * (line_size + 1));
	if (!line)
		return (NULL);
	while (i < line_size)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*
 *	Read a line in the file on the given file descriptor, appends it to the
 *	the stash and returns it. Returns NULL if there is nothing to read or 
 *	errors.
*/
char	*read_file(int fd, char *stash)
{
	char	*buf;
	int		readed;
	int		nl_index;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = 1;
	nl_index = -1;
	while (readed > 0 && nl_index == -1)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[readed] = '\0';
		stash = gnl_strjoin(stash, buf);
		nl_index = found_newline(buf);
	}
	free(buf);
	return (stash);
}

/*
 *	Reads line by line the file on the given file descriptor.
 *	Reads BUFFER_SIZE bytes at the time.
 *	Returns the readed line that can be freed, returns NULL if no line is found,
 * 	if the file descriptor is negative or in case of errors.
 * 	Can only be used on one file at the time.
*/
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), stash = NULL);
	if (!stash)
		stash = ft_strdup("");
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
