/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:38:38 by nsalles           #+#    #+#             */
/*   Updated: 2024/03/25 18:50:54 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Main function of the program.
*/
int	main(int ac, char **av)
{
	t_minirt	*mem;
	int			threads;
	int			a_aliasing;

	threads = 0;
	a_aliasing = 0;
	if (!check_args(ac, av, &threads, &a_aliasing))
		return (1);
	mem = set_minirt(av[1]);
	rendering(mem, threads, a_aliasing);
	return (0);
}
