/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:30:47 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/20 18:47:30 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	error_exit(void)
{
	write(2, "ERROR INVALID ARGUMENTS", 24);
	exit(EXIT_FAILURE);
}

void	perror_exit(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	draw_rectangle(t_vars *vars, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			img_pixel_put(vars, j, i, 0xFFAA00);
			j++;
		}
		i++;
	}
}
