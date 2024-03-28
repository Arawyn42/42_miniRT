/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:39:06 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/27 19:04:19 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
 *	Second part of the check_args function.
*/
static int	check_args2(int ac, char **av, int *anti_aliasing)
{
	if (ac == 4)
	{
		if (!check_int(av[3]) || ft_atoi(av[3]) < 0 || ft_atoi(av[3]) > 1)
		{
			print_error("Error: Third argument must be 0 or 1.");
			print_error(" 1 to activate the anti-aliasing option, 0 to ");
			print_error("deactivate it.\n");
			return (0);
		}
		*anti_aliasing = ft_atoi(av[3]);
	}
	return (1);
}

/*
 *	Returns 1 if the program's parameters are corrects. Returns 0 if not.
*/
int	check_args(int ac, char **av, int *threads, int *anti_aliasing)
{
	if (ac < 2 || ac > 4)
	{
		print_error("Error: 1 to 3 arguments needed.\n");
		print_error("Usage: ./miniRT [MAP_FILE] [THREADS_OPTION] ");
		print_error("[ANTI_ALIASING]\nWith MAP_FILE a .rt file with ");
		print_error("scene infos, THREADS_OPTION the number of threads ");
		print_error("you want (default: 0) and [ANTI_ALIASING] at 1 or 0 ");
		print_error("(default: 0)\n");
		return (0);
	}
	if (ac >= 3)
	{
		if (!check_int(av[2]) || ft_atoi(av[2]) < 0 \
			|| ft_atoi(av[2]) > SCREEN_H)
		{
			print_error("Error: Second argument must be a positive integer. T");
			print_error("here can't be more threads than the screen height.\n");
			return (0);
		}
		*threads = ft_atoi(av[2]);
	}
	if (!check_args2(ac, av, anti_aliasing) || !check_file(av[1]))
		return (0);
	return (1);
}
