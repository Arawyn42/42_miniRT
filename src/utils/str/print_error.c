/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:46:55 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/02 14:35:39 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Prints an error message on the standard error output.
*/
int	print_error(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	return (0);
}
