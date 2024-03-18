/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:39:06 by drenassi          #+#    #+#             */
/*   Updated: 2024/03/18 17:42:09 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_args(int ac, char **av, int *threads)
{
	if (ac < 2 || ac > 3)
	{
		print_error("Error: 1 or 2 arguments needed.\n");
		print_error("Usage: ./miniRT [MAP_FILE] [THREADS_OPTION]\nWith ");
		print_error("MAP_FILE a .rt file with scene infos and THREADS_OPTION");
		print_error(" the number of threads you want (default: 0).\n");
		return (0);
	}
	*threads = 0;
	if (ac == 3)
	{
		if (!check_int(av[2]) || ft_atoi(av[2]) < 0)
		{
			print_error("Error: Second argument must be a positive integer.");
			return (0);
		}
		*threads = ft_atoi(av[2]);
	}
	if (!check_file(av[1]))
		return (0);
	return (1);
}
