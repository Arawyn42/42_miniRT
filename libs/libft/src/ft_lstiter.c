/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:06:11 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:28:50 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Apply the function pointed by f to each node of the chained list lst.
 *	ARGUMENTS:
 * 		char *lst						: The chained list.
 * 		void (*f)(unsigned int, char*)	: The function.
 * 	RETURN VALUE:
 * 		void	: None.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
