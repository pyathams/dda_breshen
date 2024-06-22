/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:08:53 by pyathams          #+#    #+#             */
/*   Updated: 2024/03/23 17:19:25 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex(unsigned long n)
{
	if (n >= 16)
	{
		hex(n / 16);
		hex(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
	return (1);
}

int	ptr_print(unsigned long n)
{
	if (n == 0)
		return (write (1, "(nil)", 5), 5);
	else
	{
		write(1, "0x", 2);
		hex(n);
	}
	return (hlength(n));
}
