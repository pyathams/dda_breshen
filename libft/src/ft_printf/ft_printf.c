/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:24:37 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/23 16:41:22 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	flag_print(const char type, va_list args)
{
	if (type == 'c')
		return (print_char(args));
	else if (type == 's')
		return (putstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ptr_print(va_arg(args, unsigned long)));
	else if (type == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_put_unsigned_nbr(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hexa(va_arg(args, unsigned int), type));
	else if (type == '%')
		ft_putchar ('%');
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += flag_print(format[i], args);
			i++;
		}
		if (!format[i])
			return (count);
		if (format[i] != '%')
		{
			count++;
			ft_putchar(format[i++]);
		}
	}
	return (count);
}

// #include <stdio.h>
// #include <limits.h>
// #define __INT_MAX__ 2147483647

// int	main(void)
// {
// 	int n = 0;
// 	int *ptr = &n;
// 	int m;
// 	int o;
// 	ft_printf("%d \n",ft_printf("%c \n", 'h'));
// 	printf("%d \n",printf("%c \n", 'h'));
// 	ft_printf("%i \n",ft_printf("hello world \n"));
// 	printf("%i \n",printf("hello world \n"));
// 	ft_printf("%d \n",ft_printf("%% \n"));
// 	printf("%d \n",printf("%% \n"));
// 	ft_printf("%d \n",ft_printf("%s \n", "hello"));
// 	printf("%d \n",printf("%s \n", "hello"));
// 	int s2 = printf("%d \n", n);
// 	int s1 = ft_printf("%d \n", n);
// 	printf("%d \n", s2);
// 	ft_printf("%d \n", s1);
// 	m = printf("%p \n", (void *)ptr);
// 	o = ft_printf("%p \n", (void *)ptr);
// 	printf("%d \n",m);
// 	ft_printf("%d \n",o);
// 	int p = printf("%x \n", n);
// 	int q =ft_printf("%x \n", n);
// 	int r =printf("%X \n", n);
// 	int s =ft_printf("%X \n", n);
// 	printf("%d %d \n", p, r);
// 	ft_printf("%d %d \n", q, s);
// 	int d =ft_printf("%u \n", UINT_MAX);
// 	ft_printf("%d\n", d);
// 	int d1 =printf("%u \n", UINT_MAX);
// 	printf("%d \n", d1);
// 	printf(" %p %p ", INT_MIN, INT_MAX);
// 	// printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// }
