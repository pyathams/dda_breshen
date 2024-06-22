/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:46:13 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/23 17:25:38 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(int c);
int		print_char(va_list args);
int		putstr(char *str);
int		ft_putnbr(int n);
int		length(int n, int base);
int		ft_put_unsigned_nbr(unsigned int n);
int		llength(long long n, int base);
int		ptr_print(unsigned long n);
int		hex(unsigned long n);
int		hlength(unsigned long n);
int		ft_print_hexa(unsigned int n, const char type);
int		ft_print_hexa(unsigned int n, const char type);

#endif