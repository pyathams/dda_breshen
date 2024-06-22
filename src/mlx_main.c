/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:11:38 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/22 17:22:04 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	mlx_main(t_map	*map)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		error_exit();
	if (initialise_vars(vars, map))
	{
		free_all(vars);
		error_exit();
	}
	initialise_mlx(vars);
	mlx_hook(vars->window, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->window, 17, 1L << 17, key_hook, vars);
	draw(vars);
	mlx_loop(vars->mlx_connection);
	free_all(vars);
	return (0);
}
