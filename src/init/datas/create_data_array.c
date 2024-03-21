/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arawyn <arawyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:05:12 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/21 00:52:36 by arawyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Returns a double array of datas.
*/
char	**create_data_array(char *line)
{
	int		i;
	char	*cpy;
	char	**array;

	if (!line)
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i])
		return (NULL);
	cpy = ft_strtrim(line, " ");
	array = ft_split(cpy, ' ');
	free(cpy);
	return (array);
}
