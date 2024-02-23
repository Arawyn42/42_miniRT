/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:28:41 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:28:38 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Clear the content of the nodes of the chained list pointed by lst with the
 *	function pointed by def. Then free all the nodes and set lst to NULL.
 *	ARGUMENTS:
 *		t_list **lst		: Pointer toward the first node of a chained list.
 *		void (*del)(void *)	: Pointer toward the function to delete the content
 *								of a node.
 *	RETURN VALUE:
 *		void	: None.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	lst = NULL;
}
