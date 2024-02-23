/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:15:57 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:28:44 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Delete a node of a chained list.
 *	ARGUMENTS:
 *		t_list *lst			: Node of a chained list.
 *		void (*del)(void *)	: Pointer toward the function to delete the content
 *								of a node.
 *	RETURN VALUE:
 *		void	: None.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}
