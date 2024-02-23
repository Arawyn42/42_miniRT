/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotine <nikotine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:21:14 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/30 12:54:48 by nikotine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < lens1)
		res[i] = s1[i];
	i--;
	while (++i < lens1 + lens2)
		res[i] = s2[i - lens1];
	res[i] = '\0';
	free(s1);
	return (res);
}
