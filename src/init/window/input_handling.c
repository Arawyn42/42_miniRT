/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:49:29 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/02 15:05:32 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	user_input(int keycode, t_minirt *data)
{
	if (keycode == 65307)
		exit_handling(data);
	ft_printf("keycode = %d\n", keycode);
	return (0);
}
