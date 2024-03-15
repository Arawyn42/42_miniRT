/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arawyn <arawyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:49:29 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/15 15:58:00 by arawyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	user_input(int keycode, t_minirt *data)
{
	if (keycode == 65307)
		exit_handling(data);
	return (0);
}
