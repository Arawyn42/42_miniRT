/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:11:08 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:29:17 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Apply the function pointed by f to each node of the chained list lst.
 *	The result of the function f is stored in a new chained list.
 *	Memory for the new chained list is obtained with malloc(3), and can be freed
 *	with free(3).
 *	ARGUMENTS:
 *		t_list *lst			: The chained list.
 *		void *(*f)(void *)	: The function to passe on each node.
 *		void (*del)(void *)	: The function to delete a node in case of an error.
 *	RETURN VALUE:
 *		t_list *	: The new chained list.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*node;
	void	*content;

	if (!lst)
		return (NULL);
	res = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			free(content);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, node);
		lst = lst->next;
	}
	return (res);
}
