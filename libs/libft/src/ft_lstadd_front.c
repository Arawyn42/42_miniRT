/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:08:21 by nsalles           #+#    #+#             */
/*   Updated: 2023/12/04 10:28:28 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *	Append the node new at the front of the chained list pointed by lst.
 *	ARGUMENTS:
 *		t_list **lst	: Pointer toward the first node of a chained list.
 *		t_list *new		: A new node.
 *	RETURN VALUE:
 *		void	: None.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}
