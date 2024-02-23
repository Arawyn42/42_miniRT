/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:11:48 by nsalles           #+#    #+#             */
/*   Updated: 2023/10/18 07:36:16 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_putlohexa(unsigned int n);
int	ft_putuphexa(unsigned int n);
int	ft_putptr(unsigned long long n);
int	ft_printf_switch(va_list arg, char c);
int	ft_printf(const char *str, ...);

#endif