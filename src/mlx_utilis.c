/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utilis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:28:02 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/22 16:56:01 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	reset_vars(t_vars *vars)
{
	vars->zoom = ft_max((WIN_W / vars->map->w / 2), (WIN_H / vars->map->h / 2));
	vars->shift_x = WIN_W / 2;
	vars->shift_y = WIN_H / 6;
	vars->iso = 1;
	vars->flat = 1;
	vars->rot_x = 0;
	vars->rot_y = 0;
	vars->rot_z = 0;
}

int	initialise_vars(t_vars *vars, t_map *map)
{
	vars->map = map;
	vars->img = (t_img *)malloc(sizeof(t_img));
	if (!vars->img)
		return (1);
	reset_vars(vars);
	return (0);
}

void	initialise_mlx(t_vars	*vars)
{
	vars->mlx_connection = mlx_init();
	vars->img->img = mlx_new_image(vars->mlx_connection, WIN_W, WIN_H);
	vars->img->addr = mlx_get_data_addr(vars->img->img,
			&vars->img->bpp, &vars->img->sz_l, &vars->img->endian);
	vars->window = mlx_new_window(vars->mlx_connection, WIN_W, WIN_H, "FDF");
}
