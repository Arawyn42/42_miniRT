/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:56:34 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:23:25 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Create a node with the content content.
 *	Memory for the new node is obtained with malloc(3), and can be freed with
 *	free(3).
 *	Set next to NULL.
 *	ARGUMENTS:
 *		void *content	: The value that is assigned to the content of the node.
 *	RETURN VALUE:
 *		t_list *	: The new node.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
